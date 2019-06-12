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
#define RYLOG(format, ...)
#else
#define RY_ASSERT(CON, MSG) if (!(CON)) {cocos2d::log(MSG);assert(0);};
#define RY_ASSERT_FAILURE(MSG) cocos2d::log(MSG);assert(0);
#define RYLOG(format, ...) cocos2d::log("============>\nLOG:"#format"\nFILE: %s\nLINE: %d\n<============", ##__VA_ARGS__, __FILE__, __LINE__)
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

#define RY_REF_EXIST(REF) isRefExist(REF)
#define RY_UTIL RY_NAMESPACE::Util

RY_NAMESPACE_BEGIN

struct Util {
    
public:
    
    template<typename K, typename V>
    static bool mapHasValue(std::map<K, V>& map, K key) {
        
        auto it = map.find(key);
        if (it != map.end()) {
            return true;
        };
        return false;
    };
    
    template<typename K, typename V>
    static V mapGetValueSafe(std::map<K, V>& map, K key) {
        
        V p = nullptr;
        auto it = map.find(key);
        if (it != map.end()) {
            p = it->second;
        }
        return p;
    }
    
    template<typename K, typename V>
    static V mapGetValueSafe(std::unordered_map<K, V>& map, K key) {
        
        V p = nullptr;
        auto it = map.find(key);
        if (it != map.end()) {
            p = it->second;
        }
        return p;
    }
    
    template<typename K, typename V>
    static std::vector<K> mapGetAllKeys(std::map<K, V>& map) {
        
        std::vector<K> list;
        for (auto vk : map) {
            list.push_back(vk->first);
        }
        return list;
    };
    
    template<typename K, typename V>
    static std::vector<V> mapGetAllValues(std::map<K, V>& map) {
        
        std::vector<K> list;
        for (auto vk : map) {
            list.push_back(vk->second);
        }
        return list;
    };
    
};

RY_NAMESPACE_END

#endif /* c2d_ry_util_h */
