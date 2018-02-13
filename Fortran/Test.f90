PROGRAM Test
  IMPLICIT NONE
  
  INTEGER, DIMENSION(-1:0,3) :: m1
  INTEGER :: i,j,k=1
  
  m1 = RESHAPE(SOURCE = (/1,2,3,4,5,6/), SHAPE = (/2,3/))
  
  DO i = LBOUND(m1,1), UBOUND(m1,1)
    PRINT *, i, ': ', m1(i,:), UBOUND(m1,2)
  END DO
END PROGRAM