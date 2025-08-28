#include "../Maft.hpp"
#include "../utils/hash.hpp"
#include "../utils/matrix_utils.hpp"

#include <unordered_map>
#include <chrono>
#include <math.h>
#include <iomanip> 

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#define GLM_ENABLE_EXPERIMENTAL

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/hash.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/gtx/string_cast.hpp>

struct Glm_UniformBufferObject {
	alignas(16) glm::mat4 model;
	alignas(16) glm::mat4 view;
	alignas(16) glm::mat4 proj;
};

struct Maft_UniformBufferObject {
    alignas(16) Maft::Matrix4x4f model;
    alignas(16) Maft::Matrix4x4f view;
    alignas(16) Maft::Matrix4x4f proj;
};

std::vector<std::string> splitMat4x4Rows(const glm::mat4& g) {
    std::vector<std::string> rows;
    for (int i = 0; i < 4; ++i) {
        std::ostringstream oss;
        oss << "[";
        for (int j = 0; j < 4; ++j) {
            oss << g[j][i];
            if (j < 3) oss << ", ";
        }
        oss << "]";
        rows.push_back(oss.str());
    }
    return rows;
}

bool compareMatrix(const glm::mat4& g, const Maft::Matrix4x4f& m, float eps = 1e-5f) {
    bool ok = true;

    for (int row = 0; row < 4; ++row) 
    {
        for (int col = 0; col < 4; ++col) 
        {
            float gv = g[col][row];
            float mv = m(col, row);
            if (std::abs(gv - mv) > eps) 
            {
                ok = false;
                std::cout << "Mismatch at (" << row << "," << col << "): "
                          << gv << " vs " << mv << "\n";
            }
        }
    }

    if (!ok) 
    {
        std::cout << "GLM Matrix:\n";
        auto rows = splitMat4x4Rows(g);

        for (const auto& r : rows) 
            std::cout << r << std::endl;

        std::cout << "Maft Matrix:\n" << m << std::endl;
    }

    return ok;
}

bool compareRawLayout(const glm::mat4& g, const Maft::Matrix4x4f& m, float eps = 1e-5f) {
    const float* gData = &g[0][0];
    const float* mData = &m(0,0);

    bool ok = true;
    bool errIndex[16] = {false};

    for (int i = 0; i < 16; i++) 
    {
        if (std::abs(gData[i] - mData[i]) > eps) 
        {
            ok = false;
            errIndex[i] = true;
            std::cout << "Raw mismatch at index " << i 
                      << ": " << gData[i] << " vs " << mData[i] << "\n";
        }
    }

    if (!ok) 
    {
        std::cout << "GLM Raw:\n";
        for (int i = 0; i < 16; i++)
        {
            if (errIndex[i])
                std::cout << "\033[31m" << gData[i] << "\033[0m ";
            else
                std::cout << gData[i] << " ";
        }
        std::cout << "\n";

        std::cout << "Maft Raw:\n";
        for (int i = 0; i < 16; i++) {
            if (errIndex[i])
                std::cout << "\033[31m" << mData[i] << "\033[0m ";
            else
                std::cout << mData[i] << " ";
        }
        std::cout << "\n";

        std::cout << "GLM Matrix:\n";
        auto rows = splitMat4x4Rows(g);

        for (const auto& r : rows) 
            std::cout << r << std::endl;

        std::cout << "maft matrix\n" << m << std::endl;
    }
    return ok;
}


void test_glm_maft()
{
    static auto startTime = std::chrono::high_resolution_clock::now();
    auto currentTime = std::chrono::high_resolution_clock::now();
    float time = std::chrono::duration<float, std::chrono::seconds::period>(currentTime - startTime).count();

    Glm_UniformBufferObject ubo{};
    Maft_UniformBufferObject ubo1{};

    // glm
    ubo.model = glm::rotate(glm::mat4(1.0f), time * glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    ubo.view  = glm::lookAt(glm::vec3(2.0f, 2.0f, 2.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    ubo.proj  = glm::perspective(glm::radians(45.0f), 1.33333f, 0.1f, 10.0f);
    ubo.proj[1][1] *= -1;

    // maft
    ubo1.model = Maft::rotate(Maft::Matrix4x4f::Identity(), time * Maft::radians(90.0f), Maft::Vector3f(0.0f, 0.0f, 1.0f));
    ubo1.view  = Maft::lookAt(Maft::Vector3f(2.0f, 2.0f, 2.0f), Maft::Vector3f(0.0f, 0.0f, 0.0f), Maft::Vector3f(0.0f, 0.0f, 1.0f));
    ubo1.proj  = Maft::perspective(Maft::radians(45.0f), 1.33333f, 0.1f, 10.0f);
    ubo1.proj(1,1) *= -1;

    std::cout << "Checking MODEL matrix values...\n";
    compareMatrix(ubo.model, ubo1.model);
    std::cout << "Checking MODEL raw layout...\n";
    compareRawLayout(ubo.model, ubo1.model);

    std::cout << "Checking VIEW matrix values...\n";
    compareMatrix(ubo.view, ubo1.view);
    std::cout << "Checking VIEW raw layout...\n";
    compareRawLayout(ubo.view, ubo1.view);

    std::cout << "Checking PROJ matrix values...\n";
    compareMatrix(ubo.proj, ubo1.proj);
    std::cout << "Checking PROJ raw layout...\n";
    compareRawLayout(ubo.proj, ubo1.proj);
}
