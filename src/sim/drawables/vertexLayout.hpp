#include <GLFW/glfw3.h>
#include <glm/vec3.hpp>
#include <vector>
#include "utils.h"

struct LayoutElement{
    unsigned int type;
    unsigned int count;
    unsigned char normalised;

    static unsigned int GetSizeOfType(unsigned int type){
        switch (type){
            case (GL_FLOAT): return 4; //GL Float is 4 bytes
            case (GL_DOUBLE): return 8; //GL Double is 8 bytes
        }
        ASSERT(false);
        return 0;
    }
};

class Layout{
    private:
    std::vector<LayoutElement> elements;
    unsigned int stride;

    public:
    template<typename T>
    void Push(unsigned int type){
        static_assert(false);
    }

    template<>
    void Push<float>(unsigned int count){
        elements.push_back({GL_FLOAT, count, GL_FALSE});
        stride += LayoutElement::GetSizeOfType(GL_FLOAT);
    }

    template<>
    void Push<double>(unsigned int count){
        elements.push_back({GL_DOUBLE, count, GL_FALSE});
        stride += LayoutElement::GetSizeOfType(GL_DOUBLE);
    }

    inline const std::vector<LayoutElement> GetElements() const { return elements; }
    inline unsigned int GetStride() const { return stride; }
};
