/*
 Copyright (C) 2012-2014 Soomla Inc.
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 
 http://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

#ifndef __CCCoreEventDispatcher_H_
#define __CCCoreEventDispatcher_H_

#include "cocos2d.h"
#include "CCAbstractAggregatedEventHandler.h"
#include "CCCoreEventHandler.h"

namespace soomla {

	/** \class CCCoreEventDispatcher
		\brief Calls event handler functions when events are fired, also contains settings for StoreController.

		This class calls event handler functions when events are fired, to tie
		it to your event handler call addEventHandler(). You also set parameters
		for StoreController through this class.
	 */
    class CCCoreEventDispatcher : public CCAbstractAggregatedEventHandler<CCCoreEventHandler>, public CCCoreEventHandler {
    public:
		/**
		   This class is singleton, access it with this function.
		 */
        static CCCoreEventDispatcher *getInstance();

        bool init();

        virtual void onRewardGivenEvent(CCReward *reward);
        virtual void onRewardTakenEvent(CCReward *reward);
        virtual void onCustomEvent(cocos2d::__String *name, cocos2d::__Dictionary *extra);
    };
};

#endif //__CCCoreEventDispatcher_H_