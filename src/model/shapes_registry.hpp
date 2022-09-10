#ifndef SHAPES2D_SHAPES_REGISTRY_H_PRIVATE
#define SHAPES2D_SHAPES_REGISTRY_H_PRIVATE

#include <shapes2d/shapes_registry.hpp>


namespace shapes2d {
namespace shape {


/// registration helpers


template<typename T>
class DefaultFactory : public Factory {
protected:
    ShapePtr doCreate() override {
        return std::make_shared<T>();
    }
};


template<typename T>
FactoryPtr createDefaultFactory()
{
    return std::make_shared<DefaultFactory<T>>();
}



template<typename T>
struct ShapeRegistratorHelper {
    ShapeRegistratorHelper(const shapes2d::shape::RegistryIdentifier& id, shapes2d::shape::MetaInfo* meta) {
        meta->id = id;
        meta->factory = shapes2d::shape::createDefaultFactory<T>();
        shapes2d::shape::Registry::instance().registerShape(meta);
    }
};


/**
 * Use this macro for new shapes to register
 */
#define S2D_SHAPE_REGITRATOR_HELPER(ClassName, Id)                    \
namespace {                                                           \
                                                                      \
shapes2d::shape::MetaInfo metaInfo;                                   \
                                                                      \
using Helper = shapes2d::shape::ShapeRegistratorHelper<ClassName>;    \
const struct Registrator : public Helper {                            \
    Registrator() : Helper(Id, &metaInfo) {}                          \
} registrator;                                                        \
                                                                      \
} // ns a


// or this one
#define S2D_SHAPE_REGITRATOR_HELPER_DEFAULT(ClassName)  \
    S2D_SHAPE_REGITRATOR_HELPER(ClassName, #ClassName)



} // shape
} // ns shapes2d

#endif // #ifndef SHAPES2D_SHAPES_REGISTRY_H_PRIVATE
