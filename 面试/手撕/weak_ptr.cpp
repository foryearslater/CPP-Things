#include <atomic>

template<typename T>
struct control_block
{
    std::atomic<std::size_t> shared_count_;
    std::atomic<std::size_t> weak_count_;
    T* ptr_;
    control_block(T*p, std::size_t shared_init, std::size_t weak_init)
    :ptr_(p), shared_count_(shared_init), weak_count_(weak_init){}
};
template<typename T>
class weak_ptr
{
    template<typename U>
    friend class shared_ptr;
private:
    control_block<T>* cb_;
public:
    weak_ptr() noexcept:cb_(nullptr){}
    weak_ptr(const shared_ptr<T> &sp) noexcept: cb_(sp.cb_)
    {
        if(cb_)
        {
            cb_->weak_count_.fetch_add(1, std::memory_order_relaxed);
        }
    }
    weak_ptr(const weak_ptr& other)noexcept: cb_(other.cb_)
    {
        if(cb_)
        {
            cb_->weak_count_.fetch_add(1, std::memory_order_relaxed);
        }
    }
    weak_ptr(const weak_ptr&& other) noexcept: cb_(other.cb_)
    {
        other.cb_ = nullptr;
    }
    ~weak_ptr()
    {
        if(!cb_)
        {
            return;
        }
        std::size_t old_weak_count = cb_->weak_count_.fetch_sub(1, std::memory_order_acq_rel);
        if(old_weak_count == 1)
        {
            if(cb_->shared_count_.load(std::memory_order_acquire) == 0)
            {
                delete cb_;
            }
        }
        cb_ = nullptr;
    }
    weak_ptr& operator= (const weak_ptr& other) noexcept
    {
        if(this != &other)
        {
            weak_ptr t(other);
            swap(t);
        }
        return *this;
    }
    weak_ptr& operator= (const weak_ptr&& other) noexcept
    {
        if(this != &other)
        {
            weak_ptr t(std::move(other));
            swap(t);
        }
        return *this;
    }
    weak_ptr& operator=(const shared_ptr<T>& sp) noexcept
    {
        weak_ptr t(sp);
        swap(t);
        return *this;
    }
    void swap(weak_ptr& other) noexcept
    {
        std::swap(cb_, other.cb_);
    }
    bool expired() const noexcept
    {
        return !cb_ || cb_->shared_count_.load(std::memory_order_acquire) == 0;
    }
    shared_ptr<T> lock() const noexcept
    {
        if(expired)
        {
            return shared_ptr<T>();
        }
        std::size_t cur_count = cb_->shared_count_.load(std::memory_order_acquire);
        do
        {
            if(cur_count == 0)
            {
                return shared_ptr<T>();
            }
        }
        while((!cb_->shared_count_.compare_exchange_weak(
            cur_count,
            cur_count + 1;
            std::memory_order_acq_rel,
            std::memory_order_acquire
        )));
        std::size_t use_weak_count()const noexcept
        {
            return cb_ ? cb_->weak_count_.load(std::memory_order_acquire) : 0;
        }
    }

};
