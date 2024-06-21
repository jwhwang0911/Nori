#pragma once

// constructing octree

#include<nori/bbox.h>

NORI_NAMESPACE_BEGIN

class OcTree {
    public:
        OcTree(BoundingBox3f _bbox) : bbox(_bbox) {

        }
        // root definition
        OcTree(BoundingBox3f _bbox, int _n_prim) : bbox(_bbox), n_prim(_n_prim)
        {
            this->indices = new uint32_t[this->n_prim];
        }

        OcTree* split(const Mesh &m_mesh, const OcTree &o) {
            
        }

    private:
        BoundingBox3f   bbox;
        int             n_prim;
        OcTree          *child_list;
        uint32_t        *indices = nullptr;
};

NORI_NAMESPACE_END