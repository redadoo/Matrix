#include "../vector_types.hpp"
#include "../matrix_types.hpp"

#if !MAFT_LANG & MAFT_CXX11_FLAG
#	error "hash requires C++11 std"
#endif

namespace std
{
    template<typename T>
	struct hash<Maft::Vector<1, T> >
	{
		size_t operator()(Maft::Vector<1, T> const& v) const;
	};

	template<typename T>
	struct hash<Maft::Vector<2, T> >
	{
		size_t operator()(Maft::Vector<2, T> const& v) const;
	};

     template<typename T>
    struct hash<Maft::Vector<3, T> >
    {
        size_t operator()(Maft::Vector<3, T> const& v) const;
    };

    template<typename T>
    struct hash<Maft::Vector<4, T> >
    {
        size_t operator()(Maft::Vector<4, T> const& v) const;
    };

} // namespace std

#include "hash.inl"