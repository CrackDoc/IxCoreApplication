#ifndef IxCoreApplication_h__
#define IxCoreApplication_h__

#include "CoreExport.h"
#include "IPluginModule.h"
/**
* @class CAcCoreApplication
* @brief Ӧ�ó���ʵ������
* @note  
*/
class CORE_EXPORT IxCoreApplication
{
public:
	virtual ~IxCoreApplication(){};

	/**
	 * @fn  GetExecuteDir        
	 * @brief ��ȡ��ִ�г���·��  
	 * @return std::string ��ִ�г�������·��
	 */
	virtual const char* GetExecuteDir() const = 0;

	/**
	 * @fn  SetProductDir        
	 * @brief ���ò�ƷĿ¼, ��Ŀ¼Ĭ���ɿ�ִ�г������������Ƶ�
	 * @param const std::string & strProductDir: ��Ʒ����Ŀ¼
	 * @return void
	 */
	virtual void SetProductDir(const char* strProductDir) = 0;

	/**
	 * @fn  GetProductDir        
	 * @brief ��ȡ��ƷĿ¼  
	 * @return std::string
	 */
	virtual const char* GetProductDir()const = 0;

	/**
	 * @fn  GetDataDir        
	 * @brief   ��ȡ����Ŀ¼
	 * @return std::string
	 */
	virtual const char* GetDataDir() const = 0;

	/**
	 * @fn  GetGDALDataDir        
	 * @brief  ��ȡGDAL����Ŀ¼ 
	 * @return std::string
	 */
	virtual const char* GetGDALDataDir() const = 0;

	/**
	 * @fn  GetLogDir        
	 * @brief   ��ȡ��־Ŀ¼
	 * @return std::string
	 */
	virtual const char* GetLogDir() const = 0;

	/**
	 * @fn  GetTestDir        
	 * @brief   ��ȡ��������Ŀ¼
	 * @return std::string
	 */
	virtual const char* GetTestDir() const = 0;

	/**
	 * @fn  GetDefaultSaveDir        
	 * @brief ��ȡĬ�ϵı���·��  
	 * @return std::string
	 */
	virtual const char* GetDefaultSaveDir() const = 0;

	/**
	 * @fn  SetDefaultSaveDir        
	 * @brief ����Ĭ�ϵı���·��  
	 * @param const std::string & strDir: 
	 * @return void
	 */
	virtual void SetDefaultSaveDir(const char* strDir) = 0;

	/**
	 * @fn  GetGDALLogFile        
	 * @brief   ��ȡGDAL��־Ŀ¼
	 * @return std::string
	 */
	virtual const char* GetGDALLogFile() const = 0;

	/**
	 * @fn  GetVersion        
	 * @brief   ��ȡ�汾
	 * @return std::string
	 */
	virtual const char* GetVersion() const = 0;

	/**
	 * @fn  GetConfigDir        
	 * @brief   ��ȡ�����ļ�����Ŀ¼
	 * @return std::string
	 */
	virtual const char* GetConfigDir() const = 0;

	/**
	 * @fn  GetProfileDir        
	 * @brief   ��ȡ����Ŀ¼
	 * @return std::string
	 */
	virtual const char* GetProfileDir() const = 0;

	/**
	 * @fn  SetMajorVersion        
	 * @brief   �������汾��
	 * @param const std::string & strVersion: 
	 * @return void
	 */
	virtual void SetMajorVersion(const char* strVersion) = 0;

	/**
	 * @fn  GetMajorVersion        
	 * @brief   ��ȡ���汾��
	 * @return std::string
	 */
	virtual const char* GetMajorVersion() const = 0;

	/**
	 * @fn  SetMinorVersion        
	 * @brief   ���ôΰ汾��
	 * @param const std::string & strVersion: 
	 * @return void
	 */
	virtual void SetMinorVersion(const char* strVersion) = 0;

	/**
	 * @fn  GetMinorVersion        
	 * @brief   ��ȡ�ΰ汾��
	 * @return std::string
	 */
	virtual const char* GetMinorVersion() const = 0;

	/**
	 * @fn  SetIteratorVersion        
	 * @brief   ���õ����汾��
	 * @param const std::string & strVersion: 
	 * @return void
	 */
	virtual void SetIteratorVersion(const char* strVersion) = 0;

	/**
	 * @fn  GetIteratorVersion        
	 * @brief   ��ȡ�����汾
	 * @return std::string
	 */
	virtual const char* GetIteratorVersion() const = 0;

public:	//��ݲ���

	/**
	 * @fn  LoadPlugins        
	 * @brief   ���ز��,��Ŀ¼����
	 * @param IAcPluginModule * pPluginModule: ���ģ��
	 * @param const std::string & strFolderName: ���Ŀ¼����.�ò��Ŀ¼ֻ�ܷ���exe��������Ŀ¼
	 * @return bool ����true��ʾ���سɹ�,����false��ʾʧ��
	 */
	virtual bool LoadPlugins(IPluginModule* pPluginModule, const char* strFolderName) = 0;

	/**
	 * @fn  LoadPluginFromFile        
	 * @brief ���ز��,�������ļ�����  
	 * @param IAcPluginModule * pPluginModule: ���ģ��
	 * @param const std::string & strXmlFile: �������·��
	 * @return bool
	 */
	virtual bool LoadPluginFromFile(IPluginModule* pPluginModule, const char* strXmlFile) = 0;

	/**
	 * @fn  UnloadAllPlugin        
	 * @brief   ж�����в��
	 * @return bool
	 */
	virtual bool UnloadAllPlugin() = 0;
};
#endif // IxCoreApplication_h__
