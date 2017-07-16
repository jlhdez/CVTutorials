# Notes

1. Mat declaration, creates just the header parts
1. Loads an image from a file
 + If image cannot be loaded, `imread` returns an empty Matrix (i.e. Mat::data == NULL)
 + Has multiple flags for different options, e.g. IMREAD_COLOR
1. Mat A, B, and C all have different headers, but share the same data
1. Mat D and E share the same data but have a _region of interest_ (ROI)
1. Mat F and G now have a copy of the data of A. Modifying Mat F and G will not affect Mat A

```
Mat A, C; // 1
A = imread(argv[1], IMREAD_COLOR); // 2

Mat B(A); C = A; // 3

Mat D (A, Rect(10, 10, 100, 100) ); // 4 ROI using a rectangle
Mat E = A(Range::all(), Range(1,3)); // 4 ROI using row and column boundaries

Mat F = A.clone(); // 5
Mat G;  A.copyTo(G);
```
