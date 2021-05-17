/**
 * @file AcCoreApplication.h
 * @brief 应用程序访问
 * @note 使用方法: 
 * 1. 提供单例模式的应用程序类;
 * 2. 提供访问可执行程序目录、产品目录、日志目录、数据目录、默认保存目录等目录的接口;
 * 3. 提供版本号访问接口;
 * 4. 提供插件加载接口,和卸载插件接口;
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
* @brief 应用程序实例对象
* @note  
*/
class CORE_EXPORT CCoreApplication: public IxCoreApplication
{
public:
	CCoreApplication();
	~CCoreApplication();

	/**
	 * @fn  GetInstance        
	 * @brief 单例获取接口[静态函数]  
	 * @return CAcCoreApplication* 应用程序实例自身接口
	 */
	static CCoreApplication* GetInstance();

	/**
	 * @fn  GetExecuteDir        
	 * @brief 获取可执行程序路径  
	 * @return char* 可执行程序所在路径
	 */
	virtual const char* GetExecuteDir() const;

	/**
	 * @fn  SetProductDir        
	 * @brief 设置产品目录, 本目录默认由可执行程序向上两级推导
	 * @param const char* & strProductDir: 产品所在目录
	 * @return void
	 */
	virtual void SetProductDir(const char* strProductDir);

	/**
	 * @fn  GetProductDir        
	 * @brief 获取产品目录  
	 * @return char*
	 */
	virtual const char* GetProductDir() const;

	/**
	 * @fn  GetDataDir        
	 * @brief   获取数据目录
	 * @return char*
	 */
	virtual const char* GetDataDir() const;

	/**
	 * @fn  GetGDALDataDir        
	 * @brief  获取GDAL数据目录 
	 * @return char*
	 */
	virtual const char* GetGDALDataDir() const;

	/**
	 * @fn  GetLogDir        
	 * @brief   获取日志目录
	 * @return const char*
	 */
	virtual const char* GetLogDir() const;

	/**
	 * @fn  GetTestDir        
	 * @brief   获取测试数据目录
	 * @return const char*
	 */
	virtual const char* GetTestDir() const;

	/**
	 * @fn  GetDefaultSaveDir        
	 * @brief 获取默认的保存路径  
	 * @return const char*
	 */
	virtual const char* GetDefaultSaveDir() const;

	/**
	 * @fn  SetDefaultSaveDir        
	 * @brief 设置默认的保存路径  
	 * @param const const char* & strDir: 
	 * @return void
	 */
	virtual void SetDefaultSaveDir(const char* strDir);

	/**
	 * @fn  GetGDALLogFile        
	 * @brief   获取GDAL日志目录
	 * @return char*
	 */
	virtual const char* GetGDALLogFile() const;

	/**
	 * @fn  GetVersion        
	 * @brief   获取版本
	 * @return char*
	 */
	virtual const char* GetVersion() const;

	/**
	 * @fn  GetConfigDir        
	 * @brief   获取配置文件所在目录
	 * @return const char*
	 */
	virtual const char* GetConfigDir() const;

	/**
	 * @fn  GetProfileDir        
	 * @brief   获取概述目录
	 * @return const char*
	 */
	virtual const char* GetProfileDir() const;

	/**
	 * @fn  SetMajorVersion        
	 * @brief   设置主版本号
	 * @param const char* & strVersion: 
	 * @return void
	 */
	virtual void SetMajorVersion(const char* strVersion);

	/**
	 * @fn  GetMajorVersion        
	 * @brief   获取主版本号
	 * @return const char*
	 */
	virtual const char* GetMajorVersion() const;

	/**
	 * @fn  SetMinorVersion        
	 * @brief   设置次版本号
	 * @param const const char* & strVersion: 
	 * @return void
	 */
	virtual void SetMinorVersion(const char* strVersion);

	/**
	 * @fn  GetMinorVersion        
	 * @brief   获取次版本号
	 * @return const char*
	 */
	virtual const char* GetMinorVersion() const;

	/**
	 * @fn  SetIteratorVersion        
	 * @brief   设置迭代版本号
	 * @param const char* & strVersion: 
	 * @return void
	 */
	virtual void SetIteratorVersion(const char* strVersion);

	/**
	 * @fn  GetIteratorVersion        
	 * @brief   获取迭代版本
	 * @return const char*
	 */
	virtual const char* GetIteratorVersion() const;

public:	//快捷操作

	/**
	 * @fn  LoadPlugins        
	 * @brief   加载插件,按目录加载
	 * @param IAcPluginModule * pPluginModule: 插件模块
	 * @param const char* & strFolderName: 插件目录名称.该插件目录只能放在exe程序所在目录
	 * @return bool 返回true表示加载成功,返回false表示失败
	 */
	virtual bool LoadPlugins(IPluginModule* pPluginModule, const char* strFolderName);

	/**
	 * @fn  LoadPluginFromFile        
	 * @brief 加载插件,按配置文件加载  
	 * @param IAcPluginModule * pPluginModule: 插件模块
	 * @param const char* & strXmlFile: 插件配置路径
	 * @return bool
	 */
	virtual bool LoadPluginFromFile(IPluginModule* pPluginModule, const char* strXmlFile);

	/**
	 * @fn  UnloadAllPlugin        
	 * @brief   卸载所有插件
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
