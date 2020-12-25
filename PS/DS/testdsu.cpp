#include <string>
#include "dsu.h"

using namespace std;

void test() {
	mapped_dsu<string> md;

	md.makeSet("one");
	md.makeSet("two");
	md.makeSet("thr");
	md.makeSet("for");

	md.merge("one", "two");
	md.merge("thr", "for");
	md.merge("two", "thr");
}