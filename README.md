# Project: *Graphs for Image Segmentation*

**Name:** ***Florent Dondjeu Tschoufack***

## Goal
During this project, you will
- be exposed to the breadth of problem domains in graph theory and computer science,
- develop the skills needed to research a problem, understand its motivations and potential solutions,
- be exposed to the genesis of a problem and its historical solutions,
- practice communicating complicated material in computer science and applied mathematics.

## Description
For this project you will work individually or with a partner to learn about, implement, and document one interesting graph algorithm or data structure that was not covered during the course lecture. You will prepare a full typed report to describe the motivation for the topic, theoretical properties with some justification, and the results of your own implementation.

## Run
To run the program first compile the code by typing

```
make
```

Now to execute the code

```
./projDriver data#
```

'#' represents the number attached to the data files.

When you are done with the program, simply type

```
make clean
```

to remove the object file and the excutable.

## Output

#### Graph print

```
Pixel: A-79
Edges: B(4) F(20) G(1)
```
The number after dash next to the Pixel represents its intensity and the number in paranthesis is the edge weight between the two pixels, which is calculated by taking the positive difference of the vertices intensity.

#### Segmentation Result

```
Region 2: B-11   D-15

Region 5: E-30   A-35   F-38   C-46   G-32
```

The pixels are grouped into different regions based on their intensity.

### Different data
If you would like to create your own data, simply create a new file and follow this format:

Make a list of pixels of type char followed by any random positive value

```
A 28
C 50
X 9
```

After listing all the pixels, add a breakline (3 dashes)

```
---
```

Next, list the possible edges with the pixels

```
A C X
D F
X Y
```

**NOTE: only list the occurence of an edge once.** For example, using the list above there should be no

```
C A
```

## Analysis

### Approach
After reading an article that proposed a method of segmenting images using Graph theory, I then realized that I could use the Graph class from my labs to be able to implement this proposed algorithm. I could not quite figure out how to read images with C++, so then I drew a small image of what egdes between pixels would look like. After having this visualization, I was able to piece everything together in order to implement the segmenting algorithm.

### Deficiencies
When running the algorithm, I noticed that for cases where a vertex is not a direct neighbor of a nother vertex with a relativily same amount of brightness, were not group together. I thought of two posibbles issues that could have cause this. The first one being, how I calculated the edge weight, to which I simply subtracted both vertices's intensity and returned a positive value. The second one being, the order at which the edge pair appear during a for loop or the way I chose my numbers for the graph intensity of each vertex.

### Future Plans
In the future, I would like to first test out a bigger graph by making a complex connected graph in a data file to be read, along with giving fair intensity values, so that I can she how the algorithm works with greater number od edges and vertices. I have also heard a C++ library called opencv, which help faciliate working with images in c++. With this library I could get the correct data I need from images and be able to plot those data into a graph and test the algorithm again.
