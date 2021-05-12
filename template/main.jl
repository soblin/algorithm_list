function mat_chain_product(from::Int64, to::Int64, p::Array{Int64, 1}, costs::Array{Int64, 2})
    if costs[from, to] != -1
        return costs[from, to]
    end
    if from == to
        costs[from, to] = 0
        return 0
    end

    mincost = Inf
    for k in from:to-1
        tmp = mat_chain_product(from, k, p, costs) + mat_chain_product(k+1, to, p, costs) + p[from] * p[k+1] * p[to+1]
        if tmp < mincost
            mincost = tmp
        end
    end
    costs[from, to] = mincost
    return mincost
end

function main()
    n = parse(Int, readline())
    p = [0 for i in 1:n+1]
    
    for i in 1:n
        p1, p2 = parse.(Int, split(readline()))
        p[i] = p1
        p[i+1] = p2
    end

    costs = fill(-1, n, n)
    print(mat_chain_product(1, n, p, costs))
end

main()
