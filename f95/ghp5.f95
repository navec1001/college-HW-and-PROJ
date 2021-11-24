program ghp5
!*******************************************************
!program to get an array of 100 ints                   *
! from a file the user dictates                        *
!and sort the arrays with selection sort and quicksort *
!written by Evan                                       *
!November 2020                                         *
!Language: FORTRAN 95                                  *
!*******************************************************

!Declaring variables
character(len = 20) :: input !user file input var
integer :: i, j, k, l, m !looping vars
integer, dimension(100) :: ar_num, ar_sel, ar_qck !array to hold the 100 ints and 2 arrays for the sorted ints

!Getting user input
print *, 'Enter a file name to get integers from: '
read *, input

!getting the 100 ints from a file
open(5, file=input, status='old')
read(5, *) ar_num
close(5)

!printing the 100 ints unsorted
print *, 'Array of 100 integers UNSORTED:'
do j=1,100
    print *, ar_num(j)
end do

!copying all of the ints from ar_nums to ar_sel and ar_qck
do k=1,100
    ar_sel(k) = ar_num(k)
    ar_qck(k) = ar_num(k)
end do

!selection sorting the numbers and printing the results
call selection_sort_it(ar_sel)
print *, 'Array of 100 integers SELECTION SORTED: '
do l=1,100
    print *, ar_sel(l)
end do

!quicksorting the numbers and printing the results
call quicksort_it(ar_qck, 1, 100)
print *, 'Array of 100 integers QUICK SORTED: '
do m=1,100
    print *, ar_qck(m)
end do

contains

subroutine selection_sort_it(array)
!**********************************************************************
!Subroutine to sort a 100 element integer array by Straight Selection *
!Written by Ron, taken from Chapter 6 of CS431 Textbook               *
!March 2005                                                           *
!Adapted by Evan for GHP5 of CS431                                    *
!November 2020                                                        *
!Language: FORTRAN 90 (adapted with FORTRAN 95)                       *
!**********************************************************************
implicit none !no implicit rule
integer, dimension(100), intent(inout) :: array !defining the input array as inout and 100 element int
integer :: i, j, min, min_loc, size !loop variables, minimum value, min val location, and the size of the array
size = 100 !setting the size of the array to 100
!setting the outer do loop from 1 to penultimate array position
outer: do i=1,size-1
    min = array(i) !setting the beginning minimum value to the array(i) values
    min_loc = i !setting the beginning min val location to i
    !setting inner do loop from one after i to the last array position
    inner: do j = i + 1, size
        !consistently testing if the current array(j) value is less than the minimum value
        if (array(j).lt.min) then
            !if it is less than, set min to the current value and min loc to the current j
            min = array(j)
            min_loc = j
        endif
    end do inner
    !when the minimum value following the current location is found, swap values
    array(min_loc) = array(i)
    array(i) = min
end do outer
return
end subroutine selection_sort_it

recursive subroutine quicksort_it(array, first, last)
!*************************************************************
!Subroutine to sort a 100 element integer array by Quicksort *
!Written by t-nissie on GitHub                               *
!Link: https://gist.github.com/t-nissie/479f0f16966925fa29ea *
!July 2015                                                   *
!Adapted by Evan                                             *
!November 2020                                               *
!Language: FORTRAN 90 (adapted with FORTRAN 95)              *
!*************************************************************
implicit none !no implicit rule
integer, dimension(100), intent(inout) :: array(100) !defining the input array as inout and 100 element int
integer :: x, t, first, last !x is the pivot, t is a temp variable, first and last are the first and last locations in mini-arrays the pivot creates
integer :: i, j

x = array((first + last) / 2) !set the pivot to the middle of first and last
i = first !i starts at first
j = last !j starts at last
do
    !while the value is less than x, go up in the array
    do while (array(i) < x)
        i = i + 1
    end do
    !while the value is greater than x, go down in the array
    do while (x < array(j))
        j = j - 1
    end do
    !if i ends up greater than or equal to j, exit the do loop
    if (i >= j) exit
    !so long as you haven't exited the loop:
    !swap values (using t, the temp integer)
    t = array(i)
    array(i) = array(j)
    array(j) = t
    i = i + 1
    j = j - 1
end do
!if the first location is less than 1 less than where i ended up, call the function again but going from first to i-1
if (first < i-1) call quicksort_it(array, first, i-1)
!if the last location is greater than 1 more than where j ended up, call the function again but going from j+1 to last
if (j+1 < last) call quicksort_it(array, j+1, last)
end subroutine quicksort_it

!END OF PROGRAM
end program ghp5