%%% N Monte Carlo permutations to be performed
%%%
%%% you run the program as:
%%% MCOR4(10) for 10 permutations
%%% MCOR4(100) for 100 permutations
%%% MCOR4(1000) for 1000 permutations
%%% etc...

function SwitchingActivity=mccircuit(N)

%% for dynamic power computation we need the switching activity
Workload = [0 0 1];
MonteCarloSize=N
for i = 1:MonteCarloSize
  [x,y,z] = circuit(rand(1,1),rand(1,1),rand(1,1));
  Workload=[Workload; x, y, z];
end
vectorsNumber=size(Workload, 1);
gateInputsNumber=size(Workload, 2);
gateOutput=0*0*1;
switchesNumber=0;
for i = 1:vectorsNumber
  NewGateOutput=Workload(i,1) *  Workload(i,2) * Workload(i,3);
  %NewGateOutput
  if (gateOutput==NewGateOutput)
     continue;
  else
     gateOutput=NewGateOutput;
  end
  switchesNumber+=1;
end
switchesNumber
vectorsNumber
SwitchingActivity=switchesNumber/vectorsNumber


endfunction


