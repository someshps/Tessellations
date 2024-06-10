clc
clear all;
theta = 0:0.1:360;
xvector = ones(3600, 1);
yvector = ones(3600, 1);
% xvector(1) = 20;
% xvector(2) = 50;
for j=1
    u = j.*cosd(theta);
    v = j.*sind(theta);
    psi = u+1i*v;
%     1./psi
    m = -0.6;
    n = 0.7;
    l = 1;
    z = ((psi + (m).*(1./psi))./(1-(n).*(1./psi).^l));
    x = real(z);
    y = imag(z);
    z1 = [x(:), y(:)];
    writematrix(z1, 'fig5.csv');
    plot(x,y);
    hold on
    legend('m=-0.6 | n= 0.7 | l=1')
end



% p = 2+i*3
% q = (1/p)*13

% u = 10000.*cosd(theta);
% v = 10000.*sind(theta);
% u = 2:0.1:20;
% v = 2:0.1:20;
% psi = u+1i*v;
% m = 0.7;
% n = 0.1;
% z = ((psi + (m)*(1./psi))./(1-(n)*(1./psi)));
% x = real(z);
% y = imag(z);
% plot(x,y);

