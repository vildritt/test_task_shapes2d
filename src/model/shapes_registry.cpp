#include <shapes2d/shapes_registry.hpp>

#include <unordered_map>

namespace shapes2d {
namespace shape {


class RegistryPrivate {
public:
    Registry* q_ptr = nullptr;
    std::unordered_map<RegistryIdentifier, const MetaInfo*> m_registry;
    std::vector<const MetaInfo*> m_registryOrdered;

    RegistryPrivate(Registry* q_ptr)
        : q_ptr(q_ptr)
    {}

    bool exists(const RegistryIdentifier& id) const
    {
        return m_registry.find(id) != m_registry.end();
    }

    void registerShape(const MetaInfo *descriptor)
    {
        const auto& id = descriptor->id;
        if (exists(id)) {
            throw std::logic_error("shape with this id already registered:" + id);
        }
        m_registry[id] = descriptor;
        m_registryOrdered.push_back(descriptor);
    }

};


}} // ns


shapes2d::shape::Registry &shapes2d::shape::Registry::instance()
{
    static Registry registry;
    return registry;
}


void shapes2d::shape::Registry::registerShape(const MetaInfo *descriptor)
{
    d_ptr->registerShape(descriptor);
}


const std::vector<const shapes2d::shape::MetaInfo*>& shapes2d::shape::Registry::allRegisteredShapes() const
{
    return d_ptr->m_registryOrdered;
}


shapes2d::shape::Registry::Registry()
    : d_ptr(new shapes2d::shape::RegistryPrivate(this))
{
}


shapes2d::shape::Registry::~Registry()
{
    // NOTE: for unique_ptr
}
