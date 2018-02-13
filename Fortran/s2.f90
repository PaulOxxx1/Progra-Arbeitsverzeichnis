PROGRAM array01
  IMPLICIT NONE

  REAL :: a = 3.0
  
  CALL square( a )
  PRINT *, a
  
CONTAINS
  
  SUBROUTINE square( x )
    REAL, VALUE :: x
    x = x * x
  END SUBROUTINE square
  
END PROGRAM

