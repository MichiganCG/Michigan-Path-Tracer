# Coding Styles and Guidelines
**One Branch Per Feature**

When implementing different features for the project, a new branch should be created
for each feature. When those features are finished, a pull request should be filed to
merge that branch into the main branch. Although there are no guidelines for how to
structure commit messages, do try to keep them as descriptive as possible.

**Regarding Variable Names**

All variable names should be written in snake case while class member variables should
consist of the "m_" prefix. In snake case, all letters are in lower case and words are
split by an underscore. See pictures below for examples:

**Header Files and Source Files**

All header files (.h) and source files (.cpp | .c) will be placed in different folders.
Header files should all go in the ```include``` folder while source files should go in
the ```src``` folder. As the code base gets larger and larger, some source files will
inevitably be grouped into different sub-directories within the ```src``` folder. In
this case, the subdirectories in the "include" folder should mirror that of the ```src```
folder. See pictures below for examples:

**Third Party Libraries**

As our project increases in size, we will eventually run into a situation where we want
to use different third party libraries. These libraries can vary in size. For small
libraries with a single source file and/or a single header file, we can just toss those
files into their own subdirectory in the ```ext``` folder. For larger libraries, we will
can clone them as a submodule into the ```ext``` folder. Right in that ```ext``` folder,
there will be a ```CMakeLists.txt``` file to handle the library compilations. See pictures
below for examples:

**Brackets on a new line**

When writing various statements like ```if | for | functions | etc```, curly brackets will
usually be used. We made the decision to place curly brackets on a new line rather than an
existing line. See pictures below for examples:

**Namespace**

Finally, in most of our functions relating to the path tracer itself, they will be placed
under the ```mpt``` namespace. ```mpt``` stands for ```Michigan Path Tracer```. This is
done for a variety of reasons, most notably to prevent function collisions and to clarify
that those functions are written by ourselves and not from other libraries.
