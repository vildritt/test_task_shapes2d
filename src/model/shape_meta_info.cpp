#include <shapes2d/shape_meta_info.hpp>


shapes2d::ShapePtr shapes2d::shape::Factory::create()
{
    return doCreate();
}


shapes2d::shape::MetaInfo::MetaInfo()
    : typeIndex(shapes2d::typeIndex<int>())
{
}
