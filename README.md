# IncomaTest

Во второй задаче реализованы Tcp-сервер, принимающий запросы вида "GET" на чтение и любой другой запрос на запись значения в контейнер DataModel, и клиентская часть, которая создает 10 соединений к сереверу, отправляющая 100 запросов (90/10).

В DataModel реализованы 2 способа конкуретного доступа к данным: с помощью сигнал/слотов и мьютекса (в коде сервера оставил через сигнал/слот, закомментировав чтение/запись значения через лок мьютекса). Тесты показали, что в среднем в случае использования мьютекса 100 запросов и получение ответов занимает около 12-13 мс, а с помощью сигнал-слотов - 20-21 мс (в условиях работы клиента и сервера на одной машине и обращению к localhost).

В зависимости от структуры данных в контейнере можно использовать различные способы оптимизации: атомарные операции, транзакционность в случае БД. В данном примере, как вариант, в целях оптимизации (а она заключается в обеспечении 90% свободного чтения) можно хранить локальное состояние копии контейнера в каждом потоке клиента, а при изменении значения через сигнал/слот раздавать всем копиям актуальные значения. В данном случае каждый поток сможет свободно читать данные и отдавать клиенту за счет дополнительных расходов памяти.

Выбор TCP/UDP зависит от бизнесовой логики задачи, о чем могу рассказать при обсуждении.
