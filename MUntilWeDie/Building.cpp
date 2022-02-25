#include "Stdafx.h"
#include "Building.h"









void Building::changeStat(eStat changeStat)
{
	if (mCurStat != changeStat)
	{
		mPastStat = mCurStat;
		mCurStat = changeStat;
		mAni.ChangeCurImage(mCurStat);
	}
}