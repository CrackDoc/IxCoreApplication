#include "UnitCMake_Project.h"

#include "StlUtil.h"
#include "XDir.h"
#include "XFile.h"
#include "PluginModule.h"
#include "IxPluginDemo.h"
#include <map>
#include <string>
#include "CoreApplication.h"

BEGIN_IMPLEMENT_TEST(UnitCMake_Project)
ADD_TEST_FUNCTION(Test)
END_IMPLEMENT_TEST()

UnitCMake_Project::UnitCMake_Project(void)
{

}
UnitCMake_Project::~UnitCMake_Project(void)
{

}

void UnitCMake_Project::Test()
{
	IOx::XFile xfile = IOx::XFile("D:/VsWorkspace/git/source/repos/IxCoreApplication/build64/UnitTest/Debug/IxPluginDemod.dll");

	xfile.Normalize();

	std::string strPath = xfile.absolutePath();

	CPluginModule pluginModule;
	pluginModule.LoadPlugin("IxPluginDemod", "D:/VsWorkspace/git/source/repos/IxCoreApplication/build64/UnitTest/Debug/IxPluginDemod.dll");

	class rVisitor : public PluginInfoVisitor
	{
	public:
		rVisitor() {}
		~rVisitor() {}
		virtual void Visit(const char* strName, CPluginInfo* pluginInfo)
		{
			IPlugin* pIPlugin = pluginInfo->m_pPlugin;
			if (pIPlugin != NULL)
			{
				CIxPluginDemo* pTestPlugin = dynamic_cast<CIxPluginDemo*>(pIPlugin);
				if (pTestPlugin != NULL)
				{
					std::string testName = pTestPlugin->GetName();
					m_MapPlugins.insert(std::map<std::string, CPluginInfo*>::value_type(strName, pluginInfo));
				}
			}

		}
		std::map<std::string, CPluginInfo*>& GetPlugins() { return m_MapPlugins; }
	private:
		std::map<std::string, CPluginInfo*> m_MapPlugins;
	};
	rVisitor visitor;
	pluginModule.Travel(visitor);
	std::map<std::string, CPluginInfo*> rPluginMap = visitor.GetPlugins();

	pluginModule.UnloadPlugin("IxPluginDemod");

	std::string strDest = CCoreApplication::GetInstance()->GetExecuteDir();


}
