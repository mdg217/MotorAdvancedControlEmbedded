function dxdt = phaseplane(t, x, u)

R = 4.9;
I = 0.0059;
L = 8.2*10^(-3);
k = 0.8814;
b = 0.016;

dxdt = [ x(2);
         -(b/I)*x(2)+(k/I)*x(3);
         -(k/L)*x(2)-(R/L)*x(3)+(1/L)*u];
end


Phase Plane
[autovettori, autovalori] = eig(A)
% Funzione che calcola A*x
funzione_sistema = @(x) A*x;

% Soluzione del sistema A*x = 0
x0 = fsolve(funzione_sistema, zeros(size(A, 1), 1))

%Verify stability of position
t_interval = [0,30];
figure
plot(0,0,'r*')
xlabel("$x_1 = \theta$", "interpreter", "latex", 'FontWeight','bold', 'FontSize', 30);
ylabel("$x_2 = \dot{\theta}$",  "interpreter", "latex", 'FontWeight','bold', 'FontSize', 30);
hold on
grid on

%FOR
for i=0:0.2:2

    init_cond = [i 0 0]';
    %solution
    
    [t,x] = ode45(@(t,X) phaseplane(t,X,0) , t_interval , init_cond);
    
    %plot
    x1 = x(:,1);
    x2 = x(:,2);
    x3 = x(:,3);
   
    plot(x1, x2, 'r*'); % Utilizza 'b.' per rappresentare i punti come punti blu
    drawnow
    pause(0.2)
end

%Verify stability of position with 12v input
figure
plot(0,0,'r*')
xlabel("$x_1 = \theta$", "interpreter", "latex", 'FontWeight','bold', 'FontSize', 30);
ylabel("$x_2 = \dot{\theta}$",  "interpreter", "latex", 'FontWeight','bold', 'FontSize', 30);
hold on
grid on

%FOR    
for i=0:0.2:0.2

    init_cond = [0 0 0]';
    %solution
    
    [t,x] = ode45(@(t,X) phaseplane(t,X,12) , t_interval , init_cond);
    
    %plot
    x1 = x(:,1);
    x2 = x(:,2);
    x3 = x(:,3);
   
    plot(x1, x2, 'LineWidth', 2); % Utilizza 'b.' per rappresentare i punti come punti blu
    drawnow
    pause(0.2)
end

%Verify stability of position with 1v input
figure
plot(0,0,'r*')
xlabel("$x_1 = \theta$", "interpreter", "latex", 'FontWeight','bold', 'FontSize', 30);
ylabel("$x_2 = \dot{\theta}$",  "interpreter", "latex", 'FontWeight','bold', 'FontSize', 30);
hold on
grid on

%FOR    
for i=0:0.2:2

    init_cond = [0 i 0]';
    %solution
    
    [t,x] = ode45(@(t,X) phaseplane(t,X,0) , t_interval , init_cond);
    
    %plot
    x1 = x(:,1);
    x2 = x(:,2);
    x3 = x(:,3);
   
    plot(x1, x2, 'LineWidth', 2); % Utilizza 'b.' per rappresentare i punti come punti blu
    drawnow
    pause(0.2)
end