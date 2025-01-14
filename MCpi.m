function MCpi(N,side)
  radius = side/2
  counter = 0
  for i = 1:N
    a = 0;
    b = radius;
    x = a + (b-a) * rand(1,1)
    y = a + (b-a) * rand(1,1)
    if sqrt(x^2 + y^2) <= radius
      counter += 1
     endif
  endfor
  p = (counter / N) * 4


