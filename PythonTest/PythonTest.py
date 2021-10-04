import cplayground


def _log(*args, **kwargs):
    print(*args, **kwargs)


def _log_seg(msg):
    _log('\n'.join([
        '=' * 40,
        str(msg),
        '=' * 40
    ]))


def test_tuple_setitem():
    _log_seg('start test_tuple_setitem')

    tp = (1, 2, 3)
    ok_1 = cplayground.tuple_setitem(tp, 0, 'haha')
    _log('[1] ok: %s, tuple: %s' % (ok_1, tp))
    ok_2 = cplayground.tuple_setitem(tp, -1, None)
    _log('[2] ok: %s, tuple: %s' % (ok_1, tp))
    ok_3 = cplayground.tuple_setitem(tp, 3, 99)
    _log('[3] ok: %s, tuple: %s' % (ok_1, tp))

    _log_seg('end test_tuple_setitem')


def main():
    _log_seg('start main')

    test_tuple_setitem()

    _log_seg('end main')


if __name__ == '__main__':
    main()
    pass
