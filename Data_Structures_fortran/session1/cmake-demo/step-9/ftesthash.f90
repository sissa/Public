PROGRAM testhash
  USE hashfunc, ONLY : inthash, next_size
  IMPLICIT NONE

  INTEGER :: i
  INTEGER, PARAMETER :: nkeys = 26
  INTEGER, DIMENSION(nkeys) :: keys = (/ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, &
      11, 12, 13, 14, 15, 100, 200, 300, 9854873, 99875412, 1150384, &
      81785634, -1, -2, -3, -10 /)

  DO i=1, nkeys
      PRINT*,'key:', i, 'inthash(',keys(i),',',next_size(1000),') = ',inthash(keys(i),next_size(1000))
  END DO
END PROGRAM testhash
