
%rCalculating switching activity with the use of model from function circuit without making use of Monte Carlo activity
%sae stands for switching activity for e output
%saf stands for switching activity for f output
%sad stands for switching activity for d output

function [sae,saf,sad]=switchingactivity(a,b,c)

  [s1,s2,s3] = circuit(a,b,c)
  sae = 2*s1*(1-s1);
  saf = 2*s2*(1-s2);
  sad = 2*s3*(1-s3);
  printf("Switcing activity  for first AND GATE  with signal probability (%f) is (%f)\n",s1,sae)
  printf("Switcing activity  for second NOT GATE  with signal probability (%f) is (%f)\n",s2,saf)
  printf("Switcing activity  for third AND GATE  with signal probability (%f) is (%f)\n",s3,sad)


endfunction


