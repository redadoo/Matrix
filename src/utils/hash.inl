
MAFT_FORCE_INLINE void hash_combine(size_t &seed, size_t hash)
{
    hash += 0x9e3779b9 + (seed << 6) + (seed >> 2);
    seed ^= hash;
}

namespace std
{

    template<typename T>
	size_t hash<Maft::Vector<1, T>>::operator()(Maft::Vector<1, T> const& v) const
	{
		hash<T> hasher;
		return hasher(v.x);
	}
    
    template<typename T>
	size_t hash<Maft::Vector<2, T>>::operator()(Maft::Vector<2, T> const& v) const
	{
		size_t seed = 0;
		hash<T> hasher;
		hash_combine(seed, hasher(v.x));
		hash_combine(seed, hasher(v.y));
		return seed;
	}

    template<typename T>
	size_t hash<Maft::Vector<3, T>>::operator()(Maft::Vector<3, T> const& v) const
	{
		size_t seed = 0;
		hash<T> hasher;
		hash_combine(seed, hasher(v.x));
		hash_combine(seed, hasher(v.y));
		hash_combine(seed, hasher(v.z));
		return seed;
	}


    template<typename T>
	size_t hash<Maft::Vector<4, T>>::operator()(Maft::Vector<4, T> const& v) const
	{
		size_t seed = 0;
		hash<T> hasher;
		hash_combine(seed, hasher(v.x));
		hash_combine(seed, hasher(v.y));
		hash_combine(seed, hasher(v.z));
		hash_combine(seed, hasher(v.w));
		return seed;
	}
} // namespace std

