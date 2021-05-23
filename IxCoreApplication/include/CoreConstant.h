
#ifndef CoreConstant_h__
#define CoreConstant_h__
#include "IxCoreApplicationExport.h"


extern CORE_EXPORT bool CreateUUID(void *input);

static const double NUM_DOUBLE_PRECISION = 0.000000001;
/**
 * @fn  IsEqual        
 * @brief   
 * @param double lhs: 
 * @param double rhs: 
 * @return extern ACCORE_EXPORT bool
 */
extern CORE_EXPORT bool IsEqual(double lhs, double rhs);

static const float NUM_FLOAT_PRECISION = 0.0000001;
/**
 * @fn  IsEqual        
 * @brief   
 * @param float lhs: 
 * @param float rhs: 
 * @return extern ACCORE_EXPORT bool
 */
extern CORE_EXPORT bool IsEqual(float lhs, float rhs);

/**
 * @fn  GenerateAcObjectID        
 * @brief   
 * @return extern ACCORE_EXPORT int
 */
extern CORE_EXPORT int GenerateAcObjectID();

/**
 * @fn  GenerateAcModuleID        
 * @brief   
 * @return extern ACCORE_EXPORT int
 */
extern CORE_EXPORT int GenerateAcModuleID();

template <typename T>
void Clamp(T& rValue, const T& lhs, const T& rhs)
{
	if (rValue < lhs)
	{
		rValue = lhs;
	}

	if (rValue > rhs)
	{
		rValue = rhs;
	}
}
#endif // CoreConstant_h__
