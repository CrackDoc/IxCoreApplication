#ifndef IxCoreApplication_h__
#define IxCoreApplication_h__

#include "CoreExport.h"
#include "IPluginModule.h"
/**
* @class CAcCoreApplication
* @brief 应用程序实例对象
* @note  
*/
class CORE_EXPORT IxCoreApplication
{
public:
	virtual ~IxCoreApplication(){};

	/**
	 * @fn  GetExecuteDir        
	 * @brief 获取可执行程序路径  
	 * @return std::string 可执行程序所在路径
	 */
	virtual const char* GetExecuteDir() const = 0;

	/**
	 * @fn  SetProductDir        
	 * @brief 设置产品目录, 本目录默认由可执行程序向上两级推导
	 * @param const std::string & strProductDir: 产品所在目录
	 * @return void
	 */
	virtual void SetProductDir(const char* strProductDir) = 0;

	/**
	 * @fn  GetProductDir        
	 * @brief 获取产品目录  
	 * @return std::string
	 */
	virtual const char* GetProductDir()const = 0;

	/**
	 * @fn  GetDataDir        
	 * @brief   获取数据目录
	 * @return std::string
	 */
	virtual const char* GetDataDir() const = 0;

	/**
	 * @fn  GetGDALDataDir        
	 * @brief  获取GDAL数据目录 
	 * @return std::string
	 */
	virtual const char* GetGDALDataDir() const = 0;

	/**
	 * @fn  GetLogDir        
	 * @brief   获取日志目录
	 * @return std::string
	 */
	virtual const char* GetLogDir() const = 0;

	/**
	 * @fn  GetTestDir        
	 * @brief   获取测试数据目录
	 * @return std::string
	 */
	virtual const char* GetTestDir() const = 0;

	/**
	 * @fn  GetDefaultSaveDir        
	 * @brief 获取默认的保存路径  
	 * @return std::string
	 */
	virtual const char* GetDefaultSaveDir() const = 0;

	/**
	 * @fn  SetDefaultSaveDir        
	 * @brief 设置默认的保存路径  
	 * @param const std::string & strDir: 
	 * @return void
	 */
	virtual void SetDefaultSaveDir(const char* strDir) = 0;

	/**
	 * @fn  GetGDALLogFile        
	 * @brief   获取GDAL日志目录
	 * @return std::string
	 */
	virtual const char* GetGDALLogFile() const = 0;

	/**
	 * @fn  GetVersion        
	 * @brief   获取版本
	 * @return std::string
	 */
	virtual const char* GetVersion() const = 0;

	/**
	 * @fn  GetConfigDir        
	 * @brief   获取配置文件所在目录
	 * @return std::string
	 */
	virtual const char* GetConfigDir() const = 0;

	/**
	 * @fn  GetProfileDir        
	 * @brief   获取概述目录
	 * @return std::string
	 */
	virtual const char* GetProfileDir() const = 0;

	/**
	 * @fn  SetMajorVersion        
	 * @brief   设置主版本号
	 * @param const std::string & strVersion: 
	 * @return void
	 */
	virtual void SetMajorVersion(const char* strVersion) = 0;

	/**
	 * @fn  GetMajorVersion        
	 * @brief   获取主版本号
	 * @return std::string
	 */
	virtual const char* GetMajorVersion() const = 0;

	/**
	 * @fn  SetMinorVersion        
	 * @brief   设置次版本号
	 * @param const std::string & strVersion: 
	 * @return void
	 */
	virtual void SetMinorVersion(const char* strVersion) = 0;

	/**
	 * @fn  GetMinorVersion        
	 * @brief   获取次版本号
	 * @return std::string
	 */
	virtual const char* GetMinorVersion() const = 0;

	/**
	 * @fn  SetIteratorVersion        
	 * @brief   设置迭代版本号
	 * @param const std::string & strVersion: 
	 * @return void
	 */
	virtual void SetIteratorVersion(const char* strVersion) = 0;

	/**
	 * @fn  GetIteratorVersion        
	 * @brief   获取迭代版本
	 * @return std::string
	 */
	virtual const char* GetIteratorVersion() const = 0;

public:	//快捷操作

	/**
	 * @fn  LoadPlugins        
	 * @brief   加载插件,按目录加载
	 * @param IAcPluginModule * pPluginModule: 插件模块
	 * @param const std::string & strFolderName: 插件目录名称.该插件目录只能放在exe程序所在目录
	 * @return bool 返回true表示加载成功,返回false表示失败
	 */
	virtual bool LoadPlugins(IPluginModule* pPluginModule, const char* strFolderName) = 0;

	/**
	 * @fn  LoadPluginFromFile        
	 * @brief 加载插件,按配置文件加载  
	 * @param IAcPluginModule * pPluginModule: 插件模块
	 * @param const std::string & strXmlFile: 插件配置路径
	 * @return bool
	 */
	virtual bool LoadPluginFromFile(IPluginModule* pPluginModule, const char* strXmlFile) = 0;

	/**
	 * @fn  UnloadAllPlugin        
	 * @brief   卸载所有插件
	 * @return bool
	 */
	virtual bool UnloadAllPlugin() = 0;
};
#endif // IxCoreApplication_h__
