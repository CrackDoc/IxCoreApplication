/**
 * @file AcCoreApplication.h
 * @brief Ӧ�ó������
 * @note ʹ�÷���: 
 * 1. �ṩ����ģʽ��Ӧ�ó�����;
 * 2. �ṩ���ʿ�ִ�г���Ŀ¼����ƷĿ¼����־Ŀ¼������Ŀ¼��Ĭ�ϱ���Ŀ¼��Ŀ¼�Ľӿ�;
 * 3. �ṩ�汾�ŷ��ʽӿ�;
 * 4. �ṩ������ؽӿ�,��ж�ز���ӿ�;
 * @author Crack
 * @date 2020/06/18
 * @version V00.00.01
 */
#ifndef CoreApplication_h__
#define CoreApplication_h__
#include "IxCoreApplication.h"

#include "CoreExport.h"

class IPluginModule;
/**
* @class CAcCoreApplication
* @brief Ӧ�ó���ʵ������
* @note  
*/
class CORE_EXPORT CCoreApplication: public IxCoreApplication
{
public:
	CCoreApplication();
	~CCoreApplication();

	/**
	 * @fn  GetInstance        
	 * @brief ������ȡ�ӿ�[��̬����]  
	 * @return CAcCoreApplication* Ӧ�ó���ʵ������ӿ�
	 */
	static CCoreApplication* GetInstance();

	/**
	 * @fn  GetExecuteDir        
	 * @brief ��ȡ��ִ�г���·��  
	 * @return char* ��ִ�г�������·��
	 */
	virtual const char* GetExecuteDir() const;

	/**
	 * @fn  SetProductDir        
	 * @brief ���ò�ƷĿ¼, ��Ŀ¼Ĭ���ɿ�ִ�г������������Ƶ�
	 * @param const char* & strProductDir: ��Ʒ����Ŀ¼
	 * @return void
	 */
	virtual void SetProductDir(const char* strProductDir);

	/**
	 * @fn  GetProductDir        
	 * @brief ��ȡ��ƷĿ¼  
	 * @return char*
	 */
	virtual const char* GetProductDir() const;

	/**
	 * @fn  GetDataDir        
	 * @brief   ��ȡ����Ŀ¼
	 * @return char*
	 */
	virtual const char* GetDataDir() const;

	/**
	 * @fn  GetGDALDataDir        
	 * @brief  ��ȡGDAL����Ŀ¼ 
	 * @return char*
	 */
	virtual const char* GetGDALDataDir() const;

	/**
	 * @fn  GetLogDir        
	 * @brief   ��ȡ��־Ŀ¼
	 * @return const char*
	 */
	virtual const char* GetLogDir() const;

	/**
	 * @fn  GetTestDir        
	 * @brief   ��ȡ��������Ŀ¼
	 * @return const char*
	 */
	virtual const char* GetTestDir() const;

	/**
	 * @fn  GetDefaultSaveDir        
	 * @brief ��ȡĬ�ϵı���·��  
	 * @return const char*
	 */
	virtual const char* GetDefaultSaveDir() const;

	/**
	 * @fn  SetDefaultSaveDir        
	 * @brief ����Ĭ�ϵı���·��  
	 * @param const const char* & strDir: 
	 * @return void
	 */
	virtual void SetDefaultSaveDir(const char* strDir);

	/**
	 * @fn  GetGDALLogFile        
	 * @brief   ��ȡGDAL��־Ŀ¼
	 * @return char*
	 */
	virtual const char* GetGDALLogFile() const;

	/**
	 * @fn  GetVersion        
	 * @brief   ��ȡ�汾
	 * @return char*
	 */
	virtual const char* GetVersion() const;

	/**
	 * @fn  GetConfigDir        
	 * @brief   ��ȡ�����ļ�����Ŀ¼
	 * @return const char*
	 */
	virtual const char* GetConfigDir() const;

	/**
	 * @fn  GetProfileDir        
	 * @brief   ��ȡ����Ŀ¼
	 * @return const char*
	 */
	virtual const char* GetProfileDir() const;

	/**
	 * @fn  SetMajorVersion        
	 * @brief   �������汾��
	 * @param const char* & strVersion: 
	 * @return void
	 */
	virtual void SetMajorVersion(const char* strVersion);

	/**
	 * @fn  GetMajorVersion        
	 * @brief   ��ȡ���汾��
	 * @return const char*
	 */
	virtual const char* GetMajorVersion() const;

	/**
	 * @fn  SetMinorVersion        
	 * @brief   ���ôΰ汾��
	 * @param const const char* & strVersion: 
	 * @return void
	 */
	virtual void SetMinorVersion(const char* strVersion);

	/**
	 * @fn  GetMinorVersion        
	 * @brief   ��ȡ�ΰ汾��
	 * @return const char*
	 */
	virtual const char* GetMinorVersion() const;

	/**
	 * @fn  SetIteratorVersion        
	 * @brief   ���õ����汾��
	 * @param const char* & strVersion: 
	 * @return void
	 */
	virtual void SetIteratorVersion(const char* strVersion);

	/**
	 * @fn  GetIteratorVersion        
	 * @brief   ��ȡ�����汾
	 * @return const char*
	 */
	virtual const char* GetIteratorVersion() const;

public:	//��ݲ���

	/**
	 * @fn  LoadPlugins        
	 * @brief   ���ز��,��Ŀ¼����
	 * @param IAcPluginModule * pPluginModule: ���ģ��
	 * @param const char* & strFolderName: ���Ŀ¼����.�ò��Ŀ¼ֻ�ܷ���exe��������Ŀ¼
	 * @return bool ����true��ʾ���سɹ�,����false��ʾʧ��
	 */
	virtual bool LoadPlugins(IPluginModule* pPluginModule, const char* strFolderName);

	/**
	 * @fn  LoadPluginFromFile        
	 * @brief ���ز��,�������ļ�����  
	 * @param IAcPluginModule * pPluginModule: ���ģ��
	 * @param const char* & strXmlFile: �������·��
	 * @return bool
	 */
	virtual bool LoadPluginFromFile(IPluginModule* pPluginModule, const char* strXmlFile);

	/**
	 * @fn  UnloadAllPlugin        
	 * @brief   ж�����в��
	 * @return bool
	 */
	virtual bool UnloadAllPlugin();

protected:
	mutable char m_strMajorVersion[20];
	mutable char m_strMinorVersion[20];
	mutable char m_strVersion[20];
	mutable char m_strIteratorVersion[20];
	mutable char m_strProductDir[256];
	mutable char m_strDefaultSaveDir[256];
	mutable char m_strExcuteDir[256];
	mutable char m_strDataDir[256];
	mutable char m_strGDALDataDir[256];
	mutable char m_strLogDir[256];
	mutable char m_strTestDir[256];
	mutable char m_strGDALLogFile[256];
	mutable char m_strConfigDir[256];
	mutable char m_strProfileDir[256];
	void* m_setPluginModule;

	//std::set<IPluginModule*> m_setPluginModule;
};
#endif // CoreApplication_h__
