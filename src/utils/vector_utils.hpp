#include "../Maft.hpp"

namespace Maft
{
    template<size_t L, typename T>
    MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector<L, T> normalize(const Vector<L, T>& v)
    {
        Vector<L, T> copy(v);
        static_assert(std::numeric_limits<T>::is_iec559, "'normalize_fast' only accepts floating point types");

        T lenSq = copy.Dot(copy);
        T invLen = 1 / sqrt(lenSq);
        copy.Scale(invLen);
        return copy;
    }

} // namespace Maft
