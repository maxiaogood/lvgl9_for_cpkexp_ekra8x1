#ifndef LV_CONF_USER_H_
#define LV_CONF_USER_H_

/** Build the demos */
#define LV_BUILD_DEMOS 0

#if LV_BUILD_DEMOS
    /** Show some widgets. This might be required to increase `LV_MEM_SIZE`. */
    #define LV_USE_DEMO_WIDGETS 1
    #define LV_USE_DEMO_BENCHMARK 0
    // #define LV_USE_DEMO_MUSIC 1

#endif



#endif /* LV_CONF_USER_H_ */
