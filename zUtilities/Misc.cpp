// Supported with union (c) 2020 Union team
// Union SOURCE file

#include <chrono>
#include <random>

namespace GOTHIC_ENGINE {
  float CoerceInRange( float start, float length, float minValue, float maxValue )
  {
    start -= max( 0, start + length - maxValue );
    start += max( 0, minValue - start );
    return start;
  }

  bool Intersects( const tagRECT& a, const tagRECT& b )
  {
    return (a.left <= b.right &&
      b.left <= a.right &&
      a.top <= b.bottom &&
      b.top <= a.bottom);
  }

  int Random( int min, int max )
  {
    std::random_device rd;
    std::mt19937::result_type seed = rd() ^ (
      (std::mt19937::result_type)
      std::chrono::duration_cast<std::chrono::seconds>(
        std::chrono::system_clock::now().time_since_epoch()
        ).count() +
      (std::mt19937::result_type)
      std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::high_resolution_clock::now().time_since_epoch()
        ).count());

    std::mt19937 gen( seed );
    std::uniform_int_distribution<unsigned> distrib( min, max );

    return distrib( gen );
  }
}