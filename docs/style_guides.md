# Coding Styles and Guidelines
**One Branch Per Feature**<br>
When implementing different features for the project, a new branch should be created
for each feature. When those features are finished, a pull request should be filed to
merge that branch into the main branch. Although there are no guidelines for how to
structure commit messages, do try to keep them as descriptive as possible.

**Regarding Variable Names**<br>
All variable names should be written in snake case while class member variables should
consist of the "m_" prefix. However, since variables in structs are generally exposed
outside of the class, it is fine to exclude the "m_" prefix. In snake case, all letters
are in lower case and words are split by an underscore. See examples below:

```C++
class MyClass
{
public:
	MyClass(int my_var)
		: m_my_var(my_var) {};

private:
	int m_my_var;
};

struct MyStruct
{
	int* buffer;
	int size;
}
```

**Braces on a new line**<br>
When writing various statements like `if | for | functions | etc`, curly braces will
usually be used. We made the decision to place curly braces on a new line rather than an
existing line. See examples below:

```C++
bool my_function()
{
	while (condition)
	{
		// execute code
	}

	if (other_condition) return false;
	
	return true;
}
```

**Namespace**<br>
Finally, in most of our functions relating to the path tracer itself, they will be placed
under the `mpt` namespace. `mpt` stands for `Michigan Path Tracer`. This is
done for a variety of reasons, most notably to prevent function collisions and to clarify
that those functions are written by ourselves and not from other libraries.

**Header Files and Source Files**<br>
All header files (.hpp) and source files (.cpp) will be placed in different folders.
Header files should all go in the `include` folder while source files should go in
the `src` folder. As the code base gets larger and larger, some source files will
inevitably be grouped into different sub-directories within the `src` folder. In
this case, the subdirectories in the "include" folder should be similar to that of
the `src` folder. See examples below:

```
include
	file1.hpp
	file2.hpp
	my_folder
		file3.hpp

src
	file1.cpp
	file2.cpp
	my_folder
		file3.cpp

	main.cpp
```

**Third Party Libraries**<br>
As our project increases in size, we will eventually run into a situation where we want
to use different third party libraries. These libraries can vary in size. For small
libraries with a single source file and/or a single header file, we can just toss those
files into their own subdirectory in the `ext` folder. For larger libraries, we will
can clone them as a submodule into the `ext` folder. Right in that `ext` folder,
there will be a `CMakeLists.txt` file to handle the library compilations.
