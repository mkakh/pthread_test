all:
	gcc -lpthread m_thread.c -o m_thread -Wall
	gcc s_thread.c -o s_thread -Wall
clean:
	${RM} s_thread.o m_thread.o s_thread m_thread
