#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

/*
 * 输出:
	original element sequence of first container:
	0 1 2 3 4 5 6 7 8 9
	original element sequence of second container:
	5 6 7 8 9
	array after swap_ranges() in middle of array:
	5 6 7 8 9 0 1 2 3 4
	first container after swap_ranges() of two vectors:
	5 6 7 8 9 5 6 7 8 9
	second container after swap_ranges() of two vectors:
	0 1 2 3 4
 */

int main()
{
	int ia[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int ia2[] = { 5, 6, 7, 8, 9 };
	vector< int > vec( ia, ia+10 );
	vector< int > vec2( ia2, ia2+5 );
	ostream_iterator< int > ofile( cout, " " );

	cout << "original element sequence of first container:\n";
	copy( vec.begin(), vec.end(), ofile ); cout << '\n';

	cout << "original element sequence of second container:\n";
	copy( vec2.begin(), vec2.end(), ofile ); cout << '\n';
	// 在同一序列中进行交换
	swap_ranges( &ia[0], &ia[5], &ia[5] );

	cout << "array after swap_ranges() in middle of array:\n";
	copy( ia, ia+10, ofile ); cout << '\n';

	// 跨容器交换
	vector< int >::iterator last =
		find( vec.begin(), vec.end(), 5 );
	swap_ranges( vec.begin(), last, vec2.begin() );
	cout << "first container after "
		<< "swap_ranges() of two vectors:\n";
	copy( vec.begin(), vec.end(), ofile ); cout << '\n';
	cout << "second container after "
		<< "swap_ranges() of two vectors:\n";
	copy( vec2.begin(), vec2.end(), ofile ); cout << '\n';

	return 0;
}
