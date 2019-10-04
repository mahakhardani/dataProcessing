clear all
clc 
cp = xlsread('C:\Users\ASUS\Desktop\projet_matlab\MVT_excel\5Step.xlsx');
% Accel_X=cp(:,1);
% Accel_Y=cp(:,2);
% Accel_Z=cp(:,3);
% Gyro_X=cp(:,4);
% Gyro_Y=cp(:,5);
Gyro_Z=cp(:,6);

figure(1)
% hold on 
% subplot(3,1,1)
% plot(Accel_X,'LineWidth',2)
% axis([0 800 -6000 6000]);
% legend('Accel-X')
% title('Accel-X data')
% grid
% subplot(3,1,2)
% plot(Accel_Y,'r','LineWidth',2)
% axis([0 800 -5000 5000]);
% legend('Accel-Y')
% title('Accel-Y data')
% grid
% subplot(3,1,3)
% plot(Accel_Z,'g','LineWidth',2)
% axis([0 800 -5000 5000]);
% legend('Accel-Z')
% title('Accel-Z data')
% grid
% % 
% % 
% % figure(2)
% % subplot(3,1,1)
% % plot(Gyro_X,'LineWidth',2)
% % axis([0 800 -5000 5000]);
% % title(' Gyro-X data')
% % legend('Gyro-X')
% % grid
% % subplot(3,1,2)
% % plot(Gyro_Y,'r','LineWidth',2)
% % axis([0 800 -5000 5000]);
% % title('Gyro-Y data')
% % legend('Gyro-Y')
% % grid
% %subplot(3,1,3)
plot(Gyro_Z,'r','LineWidth',2)
axis([0 800 -6000 6000]);
title('Gyro-Z data')
legend('Gyro-Z')
grid

% figure(3)
% hold on 
% plot(Accel_X,'LineWidth',2)
% plot(Accel_Y,'r','LineWidth',2)
% plot(Accel_Z,'g','LineWidth',2)
% axis([0 800  0]);
% legend('Accel-X','Accel-Y','Accel-Z')
% title('Accel data')
% grid
% 
% 
% figure(4)
% hold on 
% plot(Gyro_X,'LineWidth',2)
% plot(Gyro_Y,'r','LineWidth',2)
% plot(Gyro_Z,'g','LineWidth',2)
% grid
% legend('Gyro-X','Gyro-Y','Gyro-Z')
% title('Gyro data')

