# Репозиторий для курса Поступашек

## Как тестировать задачи локально?

1) Создайте cmake папку в корневной папке проекта.

```
mkdir build
cmake ..
```

Полезные флаги для команды cmake ..  
-DCMAKE_BUILD_TYPE=DEBUG - добавляет дебаг-информацию в ваш бинарь, что позволяет его дебагать.  
-DCMAKE_BUILD_TYPE=ASAN - Address Sanitizer - помогает отлавливать неаккуратную работу с памятью (Обязательно тестируйте через него).  

2) Когда захотите протестировать задачку - зайдите в эту папку и сбилдите нужный вам тест.
```
cd build
make test_$(название задачи)
./test_$(название задачи)
```

Попробуйте на tasks/tutorial/sum.
