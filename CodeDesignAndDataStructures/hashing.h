#pragma once
#include <cstdint>

template <typename J>
uint32_t hash(const J &val);

template<>
uint32_t hash<uint32_t>(const uint32_t &val)
{
	return val * 2654435761;
}

template<>
uint32_t hash<int>(const int &val)
{
	return hash((uint32_t)val);
}

template<>
uint32_t hash<char>(const char &val)
{
	return hash((uint32_t)val);
}

template<>
uint32_t hash<float>(const float &val)
{
	return hash((uint32_t)val);
}

template<>
uint32_t hash<bool>(const bool &val)
{
	return hash((uint32_t)val);
}

template<size_t N>
uint32_t hash(char const (&string)[N])
{
	uint32_t hashVal = 0;
	for(size_t i = 0; i < N; i++)
	{
		hashVal = hashVal ^ hash(i);
	}
	std::cout << hashVal << std::endl;
	return hashVal;
}