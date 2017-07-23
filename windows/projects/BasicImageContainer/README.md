# Notes

+ Mat declaration, creates just the header parts
```
Mat A, C; 
```
+ Loads an image from a file
   + If image cannot be loaded, `imread` returns an empty Matrix (i.e. Mat::data == NULL)
   + Has multiple flags for different options, e.g. IMREAD_COLOR
```
A = imread(argv[1], IMREAD_COLOR); 
```
+ Mat A, B, and C all have different headers, but share the same data
```
Mat B(A); C = A; 
```
+ Mat D and E share the same data but have a _region of interest_ (ROI)
```
Mat D (A, Rect(10, 10, 100, 100) );  //  ROI using a rectangle
Mat E = A(Range::all(), Range(1,3)); //  ROI using row and column boundaries
```
+ Mat F and G now have a copy of the data of A. Modifying Mat F and G will not affect Mat A

```
Mat F = A.clone(); 
Mat G;  A.copyTo(G);
```
