#pragma once

template <typename InTransferBackend>
class InTransfer
{
public:
    template <typename T>
    void Transfer(T &a_value);
};