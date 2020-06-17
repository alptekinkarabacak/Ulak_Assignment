1.Sorunun cevabı Explanation of Secondary Node Edition isimli pdf dosyasında yazmaktadır.

Programı çalıştırmak için:

g++ -c mnUDPSend.c
g++ -c sgnbAdditionRequestTest.cpp
g++ -o sgnbAdditionRequest mnUDPSend.o sgnbAdditionRequestTest.o
g++ -c snUDPSend.c
g++ -c sgnbAdditionRequestAckTest.cpp
g++ -o sgnbAdditionRequestAck snUDPSend.o sgnbAdditionRequestAckTest.o

Komutları yazılıp kaynak kodları derlenmelidir.
Derleme sonrasında " sgnbAdditionRequest " " sgnbAdditionRequestAck " adında 2 adet binary çıktı dosyası oluşacaktır.
Önce " sgnbAdditionRequest " ardından yeni bir terminal penceresinde de " sgnbAdditionRequestAck " çalıştırılmalıdır.
Data gönderme işlemleri tamamlandığında, " sgnbAdditionRequest " penceresinde " SGNB Addition Request Message has been sent ", 
" sgnbAdditionRequestAck " terminalinde " SGNB Addition Request Acknowledge Message has been sent " mesajları gözükecektir.
Elimden geleni yaptım fakat, ne yazık ki iş yoğunluğum sebebiyle hataları ayıklayamadım. Şuan data transferi yapılmıyor.
Biraz daha zamanım olsaydı:

-> Tabi ki bug fix yapıp bu sorunu detaylı irdeleyip çözebilirdim.

-> Genel kod mimarisinin bir UML diagramını çizmeyi planlıyordum.

-> Proje derlemesi için bir Makefile hazırlamayı planlıyordum.
