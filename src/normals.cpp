#include<nori/integrator.h>
#include<nori/scene.h>

NORI_NAMESPACE_BEGIN

class NormalIntegrator : public Integrator {
    public:
        NormalIntegrator(const PropertyList &props) {

        }

        ~NormalIntegrator() {
            
        }

        Color3f Li(const Scene *scene, Sampler *sampler, const Ray3f &ray) const {
            Intersection primary_intersection;

            if(!scene->rayIntersect(ray, primary_intersection)) {
                return Color3f(0.f);
            }

            Normal3f n = primary_intersection.shFrame.n.cwiseAbs2();

            return Color3f(n.x(), n.y(), n.z());
        }

        std::string toString() const {
            return "NormalIntegrator[]";
        }
};

NORI_REGISTER_CLASS(NormalIntegrator, "normals");
NORI_NAMESPACE_END