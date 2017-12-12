#ifndef MATH_H
#define MATH_H

namespace Phantom
{
	template<typename T, typename T2>
	inline T map(T2 val, T2 in_min, T2 in_max, T out_min, T out_max)
	{
		return (val - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
	}
}

#endif /* END MATH_H */