#pragma once

// C++ Standard library includes
#include <string>
#include <map>

// Project specific headers and forward declarations
class GameObject;

// Class type definitions
typedef std::string goc_type_id;

// Class Component acts as an interface class for all the GameObject Components
// Derive Components from this class and define pure virtual methods in them.
class Component
{
public:
    // Constructor
    Component() : parent_(0) { }

    // Virtual destructor
    virtual ~Component() { }

    // Query Components by family id. Interface method.
    virtual const goc_type_id getFamilyId() const = 0;

    // Query Components by specific Component id. Interface method.
    virtual const goc_type_id getComponentId() const = 0;

    // Set owner gameobject for this Component
    void setOwner(GameObject* _go);

    // Query owner GameObject of this Component
    GameObject* getOwner() const;

private:
    GameObject* parent_;

};

inline void Component::setOwner(GameObject *_go)
{
    // If parent is already set, should we inform current parent before
    // we change the ownership of this object to another GameObject?
    parent_ = _go;
}

inline GameObject* Component::getOwner() const
{
    return parent_;
}
