# 원형 연결 리스트

## 1. 원형 연결 리스트의 개념

- **원형 연결 리스트**는 단순 연결 리스트의 마지막 노드가 첫 번째 노드를 가리키는 리스트이다.
  ![스크린샷 2024-04-06 16 51 05](https://github.com/HoyeongJeon/book_ticket/assets/78394999/3c869e54-bcec-4827-81ef-3dda43554c75)

## 2. 원형 연결 리스트의 알고리즘

- 리스트의 마지막에 노드를 삽입하는 것이 곧 리스트의 첫 번째에 노드를 삽입하는 것과 같은 의미.

### 리스트에 첫 번째 노드로 삽입하는 알고리즘

```
insertFirstNode(CL, x)
    new <- createNode();
    new.data <- x;
    if (CL == NULL) then {
        CL <- new;
        new.link <- CL;
    }

    else {
        temp <- CL;
            while(temp.link != CL) do
                temp <- temp.link;
            new.link = temp.link;
            temp.link <- new
            CL <- new;
    }
end insertFirstNode

```

### 리스트 중간에 노드를 삽입하는 알고리즘

원형 리스트 CL에 값이 x인 노드 new를 포인터 pre가 가리키는 노드 다음 노드로 삽입하는 알고리즘

```
insertMiddleNode(CL, pre, x)
    new <- createNode();
    new.data <- x;
    if(CL == NULL) then {
        CL <- new;
        new.link <- CL;
    }
    else {
        new.link <- pre.link;
        pre.link <- new;
    }
end insertMiddleNode
```

1. **공백 리스트인 경우** 노드new를 첫 번째 노드로 삽입한다.
2. **공백 리스트가 아닌 경우** 그렇지 않은 경우, pre가 가리키는 노드 다음에 노드new를 삽입한다.
   2.1 **new.link <- pre.link;** 노드 pre 다음 노드로 new를 삽입해야 하므로 노드 pre의 다음 노드를 new의 다음 노드로 연결
   2.2 **pre.link <- new;** 노드 pre의 다음 노드로 new를 삽입해야 하므로 노드 pre의 다음 노드로 new를 연결

### 노드를 삭제하는 알고리즘

CL이 가리키는 원형 리스트에서 pre가 가리키는 노드 다음 노드를 삭제하는 알고리즘
포인터 old는 삭제할 노드를 가리키고, pre는 삭제할 노드의 바로 앞 노드를 가리킨다.

```
deleteNode(CL, pre)
    if(CL == NULL) then error;
    else {
        old <- pre.link;
        pre.link <- old.link;
        if(old == CL) then
            CL <- old.link;
        free(old);
    }
end deleteNode()

```

1. **공백 리스트인 경우** 에러 메시지를 출력한다.
2. old <- pre.link; pre가 가리키는 노드 다음 노드를 삭제할 노드(old)로 지정한다.
3. pre.link <- old.link; 삭제할 노드(old)의 다음 노드(old.link)를 pre의 다음 노드로 연결한다.
4. if(old == CL) then CL <- old.link; 삭제할 노드가 첫 번째 노드인 경우, CL을 삭제할 노드의 다음 노드로 변경한다.
5. free(old); 삭제할 노드를 메모리에서 해제한다.
