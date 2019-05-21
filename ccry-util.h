//
//  c2d-ry-util.h
//  Mine
//
//  Created by ray on 2019/5/17.
//

#ifndef c2d_ry_util_h
#define c2d_ry_util_h

#include <cocos2d.h>
#include <stdio.h>

#define RY_NAMESPACE ccry

#define RY_NAMESPACE_BEGIN namespace RY_NAMESPACE {
#define RY_NAMESPACE_END };
#define RY_USING_NAMESPACE using namespace RY_NAMESPACE

#if !defined(COCOS2D_DEBUG) || COCOS2D_DEBUG == 0
#define RY_ASSERT(CON, MSG)
#define RY_ASSERT_FAILURE(MSG)
#else
#define RY_ASSERT(CON, MSG) if (!(CON)) {cocos2d::log(MSG);assert(0);};
#define RY_ASSERT_FAILURE(MSG) cocos2d::log(MSG);assert(0);
#endif

#define STR_EXPAND(tok) #tok
#define STR(tok) STR_EXPAND(tok)

#define RY_CREATE_FUNC(__TYPE__) \
static __TYPE__* create() \
{ \
    __TYPE__ *pRet = new(std::nothrow) __TYPE__(); \
    if (pRet) \
    {\
        pRet->autorelease();\
        pRet->setTypeName(STR(RY_NAMESPACE)"_"#__TYPE__);\
        return pRet; \
    } \
    else \
    { \
        delete pRet; \
        pRet = nullptr; \
        return nullptr; \
    } \
}

RY_NAMESPACE_BEGIN


struct Util {
    
public:
    
    template<class K, class V>
    static bool mapHasValue(std::map<K, V>& map, K key);
    
    template<class K, class V>
    static V mapGetValueSafe(std::map<K, V>& map, K key);
    
    template<class K, class V>
    static std::vector<K> mapGetAllKeys(std::map<K, V>& map);
    
    template<class K, class V>
    static std::vector<V> mapGetAllValues(std::map<K, V>& map);
    
};

RY_NAMESPACE_END

#define RY_REF_EXIST(REF) isRefExist(REF)
#define RY_UTIL RY_NAMESPACE::Util

#endif /* c2d_ry_util_h */
