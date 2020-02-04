#include "sphere.h"
#include "ray.h"

// Determine if the ray intersects with the sphere
Hit Sphere::Intersection(const Ray& ray, int part) const
{
    // Math help from: scratchapixel.com/lessons/3d-basic-rendering/minimal-ray-tracer-rendering
    //                 -simple-shapes/ray-sphere-intersection

    Hit intersection = {0, 0, 0};
    vec3 e = ray.endpoint - center;

    // Ray    = endpoint + direction * rando point
    // Sphere = (x - center) * (x - center) = radius^2
    //
    // f(x) = ax^2 + bx + c, 
    // where a = direction ^ 2
    //       b = 2 * endpoint * direction
    //       c = endpoint^2 - radius^2
    //
    // Discriminant = b^2 - 4ac

    double b = dot((ray.direction + ray.direction), e);
    double c = dot(e, e) - (radius * radius);
 
    double discriminant = (b * b) - (4 * c);

    if (discriminant > 0)
    {
        // There's a hit! Find where...

        double pos_root = (-b + sqrt(discriminant)) / 2; // a = 1
        double neg_root = (-b - sqrt(discriminant)) / 2;

        if(pos_root > 0)
        {
           if (neg_root > 0)
           {
               // Ray intersects in two spots, return the first!
               intersection.object = this;
               intersection.dist = neg_root;
	       intersection.part = part;
           } 
        } 
    }

    return intersection;
}

vec3 Sphere::Normal(const vec3& point, int part) const
{
    vec3 normal;

    vec3 temp = (point - center) / radius;
    normal = temp.normalized();
    return normal;
}

Box Sphere::Bounding_Box(int part) const
{
    Box box;
    TODO; // calculate bounding box
    return box;
}
