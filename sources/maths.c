#include "../include/fractol.h"

int	mandelbrotJulia_maths(struct maths_s *maths)
{
	int i;

	i = 0;
	while (i < maths->max_iteration)
	{
		maths->oldRe = maths->newRe;
		maths->oldIm = maths->newIm;
		maths->newRe = (maths->oldRe * maths->oldRe) - (maths->oldIm * maths->oldIm) + maths->pr;
		maths->newIm = 2 * maths->oldRe * maths->oldIm + maths->pi;
		if (maths->newRe * maths->newRe + maths->newIm * maths->newIm > 4)
			break;
		i++;
	}
	return(i);
}

int	burningship_maths(struct maths_s *maths)
{
	int i;

	i = 0;
	while (i < maths->max_iteration)
	{
		if(maths->newRe >= 0)
			maths->oldRe = maths->newRe;
		else
			maths->oldRe = -maths->newRe;
		if (maths->newIm >= 0)
			maths->oldIm = maths->newIm;
		else
			maths->oldIm = -maths->newIm;
		maths->newRe = (maths->oldRe * maths->oldRe) - (maths->oldIm * maths->oldIm) + maths->pr;
		maths->newIm = 2 * maths->oldRe * maths->oldIm + maths->pi;
		if (maths->newRe * maths->newRe + maths->newIm * maths->newIm > 4)
			break;
		i++;
	}
	return(i);
}
