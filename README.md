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

### Different data
If you would like to create your own data, simply create a new file and follow this format:

Make a list of pixels of type char followed by any random positive value

```
A 28
C 50
X 9
```

After listing all the pixel, add a breakline (3 dashes)

```
---
```

Next, list the possible edges with the pixels

```
A C X
D F
X Y
```

#### NOTE: only list the occurence of an edge once
for example, using the list above there should be no

```
C A
```

## Output

a sample output

```
Pixel: A-79
Adjacencies: B(4) F(20) G(1)
```
The number after dash next to the Pixel represents its intensity and the number in paranthesis is the edge weight between the two pixels.

## Analysis
