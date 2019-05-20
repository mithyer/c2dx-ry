//
//  c2d-ry-util.h
//  Mine
//
//  Created by ray on 2019/5/17.
//

#ifndef c2d_ry_util_h
#define c2d_ry_util_h

#include <cocos2d.h>
#include <string>
#include <vector>
#include <map>

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

#define RY_MAP_HAS_VALUE(MAP, KEY) RY_NAMESPACE::Util::mapHasValue(MAP, KEY)
#define RY_MAP_GET_VALUE_SAFE(MAP, KEY) RY_NAMESPACE::Util::mapGetValueSafe(MAP, KEY)
#define RY_MAP_GET_ALL_KEYS (MAP, KEY) RY_NAMESPACE::Util::mapGetAllKeys(MAP)
#define RY_MAP_GET_ALL_VALUES (MAP, KEY) RY_NAMESPACE::Util::mapGetAllValues(MAP, KEY)

#endif /* c2d_ry_util_h */
