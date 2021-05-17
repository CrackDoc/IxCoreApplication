#include "CoreApplication.h"

#include "stlUtil.h"
#include "XDir.h"
#include "XFile.h"
#include "IPlugin.h"
#include "IPluginModule.h"
#include <string>
#include <sstream>
#include <set>
CCoreApplication::CCoreApplication()
	:m_setPluginModule(new std::set<IPluginModule*>())
{
	memset(m_strMajorVersion, '\0', sizeof(char) * 20);
	memset(m_strMinorVersion, '\0', sizeof(char) * 20);
	memset(m_strIteratorVersion, '\0', sizeof(char) * 20);

	memset(m_strVersion, '\0', sizeof(char) * 20);

	memset(m_strProductDir, '\0', sizeof(char) * 256); 
	memset(m_strDefaultSaveDir, '\0', sizeof(char) * 256);

	memset(m_strExcuteDir, '\0', sizeof(char) * 256);
	memset(m_strDataDir, '\0', sizeof(char) * 256);
	memset(m_strGDALDataDir, '\0', sizeof(char) * 256);
	memset(m_strTestDir, '\0', sizeof(char) * 256);
	memset(m_strGDALLogFile, '\0', sizeof(char) * 256);
	memset(m_strConfigDir, '\0', sizeof(char) * 256);
	memset(m_strProfileDir, '\0', sizeof(char) * 256);
	memset(m_strLogDir, '\0', sizeof(char) * 256);

	strcat_s(m_strMajorVersion, "V4");
	strcat_s(m_strMinorVersion, "0");
	strcat_s(m_strIteratorVersion, "0000");
	strcat_s(m_strDefaultSaveDir, "D:/SGDownload");
}

CCoreApplication::~CCoreApplication()
{
}

CCoreApplication* CCoreApplication::GetInstance()
{
	static CCoreApplication _instance;
	return &_instance;
}

const char* CCoreApplication::GetExecuteDir() const
{
	std::string strExeDir;
	stlu::moduleDir(&strExeDir);
	stlu::normalizePath(&strExeDir, strExeDir.c_str());

	strcat_s(m_strExcuteDir, strExeDir.c_str());
	
	return m_strExcuteDir;
}

void CCoreApplication::SetProductDir(const char* strProductDir)
{
	strcat_s(m_strProductDir, strProductDir);
}

const char* CCoreApplication::GetDataDir() const
{
	std::string strDir = GetProductDir();
	strDir += "/Data";
	strcat_s(m_strDataDir, strDir.c_str());
	return m_strDataDir;
}

const char* CCoreApplication::GetGDALDataDir() const
{
	std::string strDir = GetProductDir();
	strDir += "/gdal_data";
	strcat_s(m_strGDALDataDir, strDir.c_str());
	return m_strGDALDataDir;
}

const char* CCoreApplication::GetLogDir() const
{
	std::string strDir = GetProductDir();
	strDir += "/Log";
	strcat_s(m_strLogDir, strDir.c_str());

	return m_strLogDir;

}

const char* CCoreApplication::GetProductDir() const
{
	if (std::string(m_strProductDir).empty())
	{
		std::string strExeDir = GetExecuteDir();
		IOx::XDir dir0(strExeDir.c_str());
		IOx::XDir dataDir0 = dir0.prevDir();
		dataDir0 = dataDir0.prevDir();
		return dataDir0.absolutePath();
	}
	else
	{
		return m_strProductDir;
	}
}

const char* CCoreApplication::GetTestDir() const
{
	std::string strDir = GetProductDir();
	strDir += "/Test";
	strcat_s(m_strTestDir, strDir.c_str());

	return m_strTestDir;
}

const char* CCoreApplication::GetDefaultSaveDir() const
{
	return m_strDefaultSaveDir;
}

void CCoreApplication::SetDefaultSaveDir( const char* strDir )
{
	strcat_s(m_strDefaultSaveDir, strDir);
}

const char* CCoreApplication::GetGDALLogFile() const
{
	std::string strDir = GetLogDir();
	strDir += "/gdal.log";
	strcat_s(m_strGDALLogFile, strDir.c_str());
	return m_strGDALLogFile;
}

const char* CCoreApplication::GetVersion() const
{
	std::stringstream ss;
	ss << m_strMajorVersion << "." << m_strMinorVersion;
	strcat_s(m_strVersion, ss.str().c_str());

	return m_strVersion;

}

const char* CCoreApplication::GetConfigDir() const
{
	std::string strDir = GetProductDir();
	strDir += "/Config";
	strcat_s(m_strConfigDir, strDir.c_str());

	return m_strConfigDir;
}

const char* CCoreApplication::GetProfileDir() const
{
	std::string strDir = GetConfigDir();
	strDir += "/Profiles";
	strcat_s(m_strProfileDir, strDir.c_str());

	return m_strProfileDir;
}

void CCoreApplication::SetMajorVersion(const char* strVersion)
{
	strcat_s(m_strMajorVersion, strVersion);
}

const char* CCoreApplication::GetMajorVersion() const
{
	return m_strMajorVersion;
}

void CCoreApplication::SetMinorVersion(const char* strVersion)
{
	strcat_s(m_strMinorVersion, strVersion);
}

const char* CCoreApplication::GetMinorVersion() const
{
	return m_strMinorVersion;
}

void CCoreApplication::SetIteratorVersion(const char* strVersion)
{
	strcat_s(m_strIteratorVersion, strVersion);
}

const char* CCoreApplication::GetIteratorVersion() const
{
	return m_strIteratorVersion;
}

const std::string STR_PLUGIN_PREFIX = "Plugin";
const std::string STR_PLUGIN_SUFFIX = ".dll";

class CPluginDirVisitor : public IOx::XDir::DirVisitor
{
public:
	CPluginDirVisitor(IPluginModule* pPluginModule)
		: m_pPluginModule(pPluginModule)
	{}
	~CPluginDirVisitor(){}

	bool apply(IOx::XDir& rDir)
	{
		return true;
	}

	bool apply(IOx::XFile& rFile)
	{
		std::string strFilePath = rFile.absolutePath();
		std::string strBaseName = rFile.baseName();
		bool bPlugin0 = stlu::isStartWith(strBaseName.c_str(), STR_PLUGIN_PREFIX.c_str());
		bool bPlugin1 = stlu::isEndWith(strFilePath.c_str(), STR_PLUGIN_SUFFIX.c_str());
		if (bPlugin0 && bPlugin1)
		{
			bool bLoadOK = m_pPluginModule->LoadPlugin(strBaseName.c_str(),strFilePath.c_str());

			//write log
			int a = 0;
		}

		return true;
	}

protected:
	IPluginModule* m_pPluginModule;
};

bool CCoreApplication::LoadPlugins(IPluginModule* pPluginModule, const char* strFolderName)
{
	if (NULL == pPluginModule)
	{
		return false;
	}

	std::string strExeDir = GetExecuteDir();
	std::string strPluginDir = strExeDir + strFolderName + "/";

	IOx::XDir xdir0(strPluginDir.c_str());
	CPluginDirVisitor dv(pPluginModule);
	xdir0.travel(dv);

	std::set<IPluginModule*>& setPluginModule = *static_cast<std::set<IPluginModule*>*>(m_setPluginModule);

	setPluginModule.insert(pPluginModule);

	return true;
}

bool CCoreApplication::LoadPluginFromFile( IPluginModule* pPluginModule, const char* strXmlFile )
{
	if (NULL == pPluginModule)
	{
		return false;
	}

	bool bExist = stlu::fileExist(strXmlFile);
	if (!bExist)
	{
		return false;
	}
	// 然后遍历xml 里面所有的插件加载到相应的文件夹下

	//bool bLoadOK = pPluginModule->LoadPluginsFromFile(strXmlFile);

	return false;
}

bool CCoreApplication::UnloadAllPlugin()
{
	std::set<IPluginModule*>& setPluginModule = *static_cast<std::set<IPluginModule*>*>(m_setPluginModule);

	for (std::set<IPluginModule*>::iterator it = setPluginModule.begin();
		it != setPluginModule.end(); ++it)
	{
		IPluginModule* pPluginModule = (*it);
		if (NULL == pPluginModule)
		{
			continue;
		}

		pPluginModule->UnloadAllPlugins();
	}
	setPluginModule.clear();

	return true;
}
