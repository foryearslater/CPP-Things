#pragma once

#include <string_view>

template <typename T>
struct FsTypeNameTraits
{
    static_assert(false, "No Type Name Traits.");

    static constexpr std::string_view Name()
    {
        return "NoName";
    }
};

#define DEFINE_FS_TYPE_NAME_TRAITS(TYPE, NAME)   \
    template <>                                  \
    struct FsTypeNameTraits<TYPE>                \
    {                                            \
        static constexpr std::string_view Name() \
        {                                        \
            return NAME;                         \
        }                                        \
    };

DEFINE_FS_TYPE_NAME_TRAITS(double, "double")
DEFINE_FS_TYPE_NAME_TRAITS(float, "float")
DEFINE_FS_TYPE_NAME_TRAITS(int8_t, "int8")
DEFINE_FS_TYPE_NAME_TRAITS(uint8_t, "uint8")
DEFINE_FS_TYPE_NAME_TRAITS(int16_t, "int16")
DEFINE_FS_TYPE_NAME_TRAITS(uint16_t, "uint16")
DEFINE_FS_TYPE_NAME_TRAITS(int32_t, "int32")
DEFINE_FS_TYPE_NAME_TRAITS(uint32_t, "uint32")
DEFINE_FS_TYPE_NAME_TRAITS(int64_t, "int64")
DEFINE_FS_TYPE_NAME_TRAITS(uint64_t, "uint64")
DEFINE_FS_TYPE_NAME_TRAITS(bool, "bool")
