clc
clear all
% filename='Q_TC6_400_QUAD.msh';
filename='Q_TC9_TRI.msh';
A = fileread(filename);
fid1 = fopen(filename, 'rt');% opening realdomain file
r = textscan(fid1, '%s', 'delimiter', '\n');

format long;

idx1 = find(strcmp(r{1}, '$Nodes'), 1, 'first');
idx2 = find(strcmp(r{1}, '$EndNodes'), 1, 'first');
a = idx1+2;  % Top RowRange  for the Face Data extraction
b=idx2-1; % Bottom RowRange  for the Face Data extraction
Mesh_Nodes = readtess(filename,0,-4,a,b);

idx1 = find(strcmp(r{1}, '$Elements'), 1, 'first');
idx2 = find(strcmp(r{1}, '$EndElements'), 1, 'first');
a = idx1+2;  % Top RowRange  for the Face Data extraction
b=idx2-1; % Bottom RowRange  for the Face Data extraction
Mesh_Elements = readtess(filename,0,-5,a,b);
sz_ME = size(Mesh_Elements);
ss= sz_ME(2) +1;
Mesh_Elements(:,ss)= [0]; % Assigning ZERO Flag Value to the LAST Column
ff=0;
c=0;
for ik = 1:sz_ME(1)
    if Mesh_Elements(ik,2)==2 
        ff=0; % means Triangular Mesh Element
        c=c+1;
    end
   if Mesh_Elements(ik,2)==3
       ff=1;    % means Quadrilateral Mesh Element
       c=c+1;
   end
end
p=sz_ME(1)-c; q=p+1;
Angle = zeros(c,2); % 1st column is minimum and 2nd column is maximum angle.
AspectRatio = zeros(c,1); l=0;
Skewness = zeros(c,1);
for ik = q:sz_ME(1)
    l=l+1; dd =0;
   if Mesh_Elements(ik,2)==2    % Triangular Element
       v1 = Mesh_Elements(ik,6); v2 = Mesh_Elements(ik,7); v3 = Mesh_Elements(ik,8);
       n1 = Mesh_Nodes(v1,[2:3]); n2 = Mesh_Nodes(v2,[2:3]); n3 = Mesh_Nodes(v3,[2:3]);
       V =  [n1;n2;n3];
       Angles = TRIangles(V);
       min_a=min(Angles); max_a=max(Angles);
       Angle(l,1) = Angle(l,1) + min_a;  Angle(l,2) = Angle(l,2) + max_a;
       V1=[V; n1];
       for t=1:3
           co1=V1(t,[1:2]); co2=V1(t+1,[1:2]);
           co = [co1;co2];
           d = pdist(co, 'euclidean');
           dd = [dd d];
       end
       dd(1) = [];
       dmax = max(dd); dmin = min(dd); val = dmax/ dmin;
       AspectRatio(l,1) = AspectRatio(l,1) + val;
       
       s1 = (dmax-60)/ (180-60); s2 = (60-dmin)/ 60;
       Skewness(l,1) = Skewness(l,1) + max(s1,s2);
   end
   
   if Mesh_Elements(ik,2)==3    % Quadrilateral Element
       v1 = Mesh_Elements(ik,6); v2 = Mesh_Elements(ik,7); v3 = Mesh_Elements(ik,8); v4 = Mesh_Elements(ik,9);
       n1 = Mesh_Nodes(v1,[2:3]); n2 = Mesh_Nodes(v2,[2:3]); n3 = Mesh_Nodes(v3,[2:3]); n4 = Mesh_Nodes(v4,[2:3]);
       V =  [n1;n2;n3;n4];
       Angles = QUADangles(V);
       min_a=min(Angles); max_a=max(Angles);
       Angle(l,1) = Angle(l,1) + min_a;  Angle(l,2) = Angle(l,2) + max_a;
        
       V1=[V; n1];
       for t=1:3
           co1=V1(t,[1:2]); co2=V1(t+1,[1:2]);
           co = [co1;co2];
           d = pdist(co, 'euclidean');
           dd = [dd d];
       end
       dd(1) = [];
       dmax = max(dd); dmin = min(dd); val = dmax/ dmin;
       AspectRatio(l,1) = AspectRatio(l,1) + val;
       
    s1 = (dmax-90)/ 90; s2 = (90-dmin)/ 90;
       Skewness(l,1) = Skewness(l,1) + max(s1,s2);
   end
 
end

figure

subplot(3,1,1)
lp = histogram(AspectRatio,50,'FaceColor',[.60,.60,.60]); 
 
set(gca,'XGrid','on');
set(gca,'YGrid','on');
set(gca,'box','off');

t = lp.BinWidth; z = size(lp.BinCounts); sz = z(2);
putx = (t*sz)/2;  
puty = max(lp.Values)*0.8;
txt=['Total number of Mesh Elements = ', num2str(c)];
text(putx, puty,txt,'horizontalalignment','center','fontsize',15,'interpreter','latex') ;
p = (max(lp.Values) + min(lp.Values))/2;
ah = putx/4.8;
text(-ah,p,'$\bf |ar|_{\it m.e}$','HorizontalAlignment','left','fontsize',16,'interpreter','latex') ;

xlabel('Aspect ratio values \rightarrow');
ylabel('Count Density \rightarrow');
title('MESH ELEMENT ASPECT RATIO');

hold on

subplot(3,1,2)
Angle(:,1)=real(Angle(:,1));
ad = Angle(:,1);
if ff==0
    be = linspace(0.,60.,31);
elseif ff==1
    be = linspace(0.,90.,46); 
end
bm =(be(1:end-1)+be(2:end))/2.;
hc = histogram(Angle(:,1),be);

if ff==0
    poor = bm <  20. ;
    okay =(bm >= 20.  & bm <  38. );
    good =(bm >= 38.  & bm <  48. );
    best = bm >= 48.  & bm <  60. ;
elseif ff==1
    poor = bm <  40. ;
    okay =(bm >= 40.  & bm <  63. );
    good =(bm >= 63.  & bm <  78. );
    best = bm >= 78.  & bm <  90. ;
end

r = [.85,.00,.00] ; y = [1.0,.95,.00] ;
g = [.00,.90,.00] ; k = [.60,.60,.60] ;
    
    bar(bm(poor),hc.Values(poor),1.05,'facecolor',r,'edgecolor',r) ;
    bm =(be(1:end-1)+be(2:end))/2.;  hc = histogram(Angle(:,1),be);
    bar(bm(okay),hc.Values(okay),1.05,'facecolor',y,'edgecolor',y) ; 
    hold on;
    bm =(be(1:end-1)+be(2:end))/2.; hc = histogram(Angle(:,1),be);
    bar(bm(good),hc.Values(good),1.05,'facecolor',g,'edgecolor',g) ; 
    hold on;
    bm =(be(1:end-1)+be(2:end))/2.; hc = histogram(Angle(:,1),be);
    bar(bm(best),hc.Values(best),1.05,'facecolor',k,'edgecolor',k) ;
axis tight
set(gca,'XGrid','on');
set(gca,'YGrid','on');
set(gca,'box','off');
set(gca,'XLimMode','manual');
if ff==0
    set(gca,'xlim',[0.,60.]);
    set(gca,'xtick',0:5:60);
    pq=-7;
elseif ff==1
    set(gca,'xlim',[0.,90.]);
    set(gca,'xtick',0:9:90);
    pq=-11;
end
p = (max(hc.Values)+min(hc.Values))/2;
 
text(pq,p,'$\bf \angle\theta_{min}$','HorizontalAlignment','left','fontsize',16,'interpreter','latex') ;
xlabel('\theta Values \rightarrow'); % ('Minimum Angle values ->');
ylabel('Count Density \rightarrow');
title('MESH ELEMENT MINIMUM ANGLE STATISTICS');

hold on

subplot(3,1,3)
ad1 = real(Angle(:,2));
if ff==0
    be1 = linspace(60.,180.,61);
elseif ff==1
    be1 = linspace(90.,180.,46);
end
bm1 =(be1(1:end-1)+be1(2:end))/2.;
hc1 = histogram(ad1(:,1),be1);

if ff==0
    poor1 = bm1 >  135. ;
    okay1 =(bm1 >= 85.  & bm1 <  135. );
    good1 =(bm1 >= 72.  & bm1 <  85. );
    best1 = bm1 >= 60.  & bm1 <  72. ;
elseif ff==1
    poor1 = bm1 >  140. ;
    okay1 =(bm1 >= 120.  & bm1 <  140. );
    good1 =(bm1 >= 100.  & bm1 <  120. );
    best1 = bm1 >= 90.  & bm1 <  100. ;
end
r1 = [.85,.00,.00] ; y1 = [1.0,.95,.00] ;
g1 = [.00,.90,.00] ; k1 = [.60,.60,.60] ;
    
    bar(bm1(poor1),hc1.Values(poor1),1.05,'facecolor',r1,'edgecolor',r1) ; hold on;
    bm1 =(be1(1:end-1)+be1(2:end))/2.;  hc1 = histogram(ad1(:,1),be1);
    bar(bm1(okay1),hc1.Values(okay1),1.05,'facecolor',y1,'edgecolor',y1) ; 
    hold on;
    bm1 =(be1(1:end-1)+be1(2:end))/2.; hc1 = histogram(ad1(:,1),be1);
    bar(bm1(good1),hc1.Values(good1),1.05,'facecolor',g1,'edgecolor',g1) ; 
    hold on;
    bm1 =(be1(1:end-1)+be1(2:end))/2.; hc1 = histogram(ad1(:,1),be1);
    bar(bm1(best1),hc1.Values(best1),1.05,'facecolor',k1,'edgecolor',k1) ;
axis tight
set(gca,'XGrid','on');
set(gca,'YGrid','on');
set(gca,'box','off');
set(gca,'XLimMode','manual');
if ff==0
    set(gca,'xlim',[60.,180.]);
    set(gca,'xtick',60:10:180);
    pp = 45;
elseif ff==1
    set(gca,'xlim',[90.,180.]);
    set(gca,'xtick',90:9:180);
    pp = 78.5;
end
p1 = (max(hc1.Values)+min(hc1.Values))/2;
text(pp,p1,'$\bf \angle\theta_{max}$','HorizontalAlignment','left','fontsize',16,'interpreter','latex') ;

xlabel('\theta Values \rightarrow');
ylabel('Count Density \rightarrow');
title('MESH ELEMENT MAXIMUM ANGLE STATISTICS');

% figure
% histogram(Skewness,50);
% grid on
% grid minor
% xlabel('Skewness values ->');
% ylabel('Count Density ->');
% title('MESH ELEMENT SKEWNESS STATISTICS');